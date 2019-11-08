#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Added constructor
Process::Process(int pid) {
    pid_ = pid;    
    user_ = LinuxParser::User(pid_); 
    command_ = LinuxParser::Command(pid_);
    ram_ = LinuxParser::Ram(pid_);
    this->SetCpuUtilization();
}

void Process::SetCpuUtilization () {
    vector<string> data = LinuxParser::CpuUtilization(pid_);
    int utime, stime, cutime, cstime, starttime;
    int total_time, seconds;
    long uptime;    
    
    uptime = LinuxParser::UpTime();

    utime = std::stoi(data[13]);
    stime = std::stoi(data[14]);
    cutime = std::stoi(data[15]);
    cstime = std::stoi(data[16]);
    starttime = std::stoi(data[21]);

    /* Calculation taken from here:
    https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
    */

    seconds = uptime - (starttime / sysconf(_SC_CLK_TCK));
    if (seconds <= 0) { cpu_usage_ = 0.0;}
    else {
        total_time = utime + stime + cutime + cstime;       
        cpu_usage_ = ((total_time /  sysconf(_SC_CLK_TCK)) / float(seconds));
    }    
}

// DONE: Return this process's ID
int Process::Pid() const { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_usage_; }

// DONE: Return the command that generated this process
string Process::Command() const { return command_; }

// DONE: Return this process's memory utilization
string Process::Ram() const { return ram_; }

// DONE: Return the user (name) that generated this process
string Process::User() const { return user_; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const {   
    return cpu_usage_ < a.cpu_usage_;        
}
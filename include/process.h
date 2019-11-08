#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid() const;                               // DONE: See src/process.cpp
  std::string User() const;                      // DONE: See src/process.cpp
  std::string Command() const;                   // DONE: See src/process.cpp
  float CpuUtilization() const;                  // DONE: See src/process.cpp
  void SetCpuUtilization ();
  std::string Ram() const;                       // DONE: See src/process.cpp
  long int UpTime();                       // DONE: See src/process.cpp
  bool operator<(Process const& a) const;  // DONE: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
 int pid_;
 std::string user_;
 std::string command_; 
 std::string ram_;
 float cpu_usage_;
};

#endif
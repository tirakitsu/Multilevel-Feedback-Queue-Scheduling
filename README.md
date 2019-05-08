# Multilevel-Feedback-Queue-Scheduling
The goal of the project was to simulate a three-level multi-level feedback queue scheduler. Each queue
in the scheduler would use round robin scheduling. The first level would have a small
quantum to let I/O-bound processes get through quickly. The second level would have a
medium quantum and the third level would have the largest quantum. The three queue
levels would operate under a strict priority scheme--for a process in the second or third
level queues to execute, there is be no process waiting to execute in an upper level
queue. When a process arrives in an upper level queue while a process is executing in
a lower level queue, the lower level process is immediately stripped of the CPU and
remains in place in the queue until it gets to execute again.

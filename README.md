 # 42_Philosophers

**Project Overview:**

This project serves as a training exercise for multi-threading and multi-process programming, employing mutexes and semaphores. It consists of three distinct programs that provide a unique twist on the renowned Dining Philosophers problem while adhering to the same fundamental principles. Additionally, this project offers valuable insights into C optimization, demanding efficient CPU usage to ensure the philosophers' survival.

**Project Requirements:**

This project must be implemented in the C programming language, adhering to the 42 Norm. Any memory leaks, crashes, undefined behavior, or norm violations will result in a project score of 0.

A group of philosophers is seated around a circular table, engaging in three activities: eating, thinking, or sleeping.

While a philosopher is eating, they must not be thinking or sleeping. Similarly, while sleeping, they should neither eat nor think. Philosophers must not engage in two activities simultaneously.

The philosophers are seated at a round table, which features a central bowl of spaghetti and multiple forks.

As spaghetti is challenging to serve and consume with a single fork, each philosopher must use two forks, one for each hand.

It is essential to prevent philosophers from experiencing starvation. Therefore, every philosopher must eat.

Philosophers do not communicate with one another, and they remain unaware of another philosopher's impending demise.

Upon completing their meal, each philosopher will release their forks and proceed to sleep.

After sleeping, philosophers will begin thinking.

The simulation will only conclude when a philosopher dies.

Each program should accept the following options:

number_of_philosophers: Represents the number of philosophers and also the number of forks.
time_to_die: Measured in milliseconds, this specifies the maximum time a philosopher can go without eating before they perish.
time_to_eat: Measured in milliseconds, this represents the time it takes for a philosopher to complete a meal while holding two forks.
time_to_sleep: Measured in milliseconds, this denotes the duration a philosopher spends sleeping.
number_of_times_each_philosopher_must_eat (optional): If specified, the simulation will conclude only when all philosophers have eaten at least this many times. If omitted, the simulation ends upon a philosopher's death.
Each philosopher should be assigned a unique number ranging from 1 to number_of_philosophers.

Philosopher number 1 is seated next to philosopher number number_of_philosophers. Any philosopher with number N is positioned between philosopher N - 1 and philosopher N + 1.

All changes in a philosopher's status must be recorded in the following format (with X representing the philosopher number and timestamp_in_ms indicating the current timestamp in milliseconds):

timestamp_in_ms X has taken a fork
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

The displayed statuses must be neatly formatted and not intertwined with the statuses of other philosophers.

The time gap between a philosopher's death and the printing of their demise should not exceed 10 milliseconds.

Above all, the philosophers must make every effort to avoid perishing prematurely.

This project involves implementing the Dining Philosophers problem with specific guidelines and constraints, necessitating careful planning, synchronization, and optimization for CPU usage.





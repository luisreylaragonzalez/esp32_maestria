
# Link:
https://www.freertos.org/about-RTOS.html

# What is a General Purpose Operating System?
An operating system is a computer program that supports a computer's basic functions, and provides services to other programs (or applications) that run on the computer. The applications provide the functionality that the user of the computer wants or needs. The services provided by the operating system make writing the applications faster, simpler, and more maintainable. If you are reading this web page, then you are using a web browser (the application program that provides the functionality you are interested in), which will itself be running in an environment provided by an operating system.

# What is an RTOS?
Most operating systems appear to allow multiple programs to execute at the same time. This is called multi-tasking. In reality, each processor core can only be running a single thread of execution at any given point in time. A part of the operating system called the scheduler is responsible for deciding which program to run when, and provides the illusion of simultaneous execution by rapidly switching between each program.
The type of an operating system is defined by how the scheduler decides which program to run when. For example, the scheduler used in a multi user operating system (such as Unix) will ensure each user gets a fair amount of the processing time. As another example, the scheduler in a desk top operating system (such as Windows) will try and ensure the computer remains responsive to its user. [Note: FreeRTOS is not a big operating system, nor is it designed to run on a desktop computer class processor, I use these examples purely because they are systems readers will be familiar with]

The scheduler in a Real Time Operating System (RTOS) is designed to provide a predictable (normally described as deterministic) execution pattern. This is particularly of interest to embedded systems as embedded systems often have real time requirements. A real time requirements is one that specifies that the embedded system must respond to a certain event within a strictly defined time (the deadline). A guarantee to meet real time requirements can only be made if the behaviour of the operating system's scheduler can be predicted (and is therefore deterministic).

Traditional real time schedulers, such as the scheduler used in FreeRTOS, achieve determinism by allowing the user to assign a priority to each thread of execution. The scheduler then uses the priority to know which thread of execution to run next. In FreeRTOS, a thread of execution is called a task

# What is FreeRTOS?
[see also "more about FreeRTOS"]
FreeRTOS is a class of RTOS that is designed to be small enough to run on a microcontroller - although its use is not limited to microcontroller applications.

A microcontroller is a small and resource constrained processor that incorporates, on a single chip, the processor itself, read only memory (ROM or Flash) to hold the program to be executed, and the random access memory (RAM) needed by the programs it executes. Typically the program is executed directly from the read only memory.

Microcontrollers are used in deeply embedded applications (those applications where you never actually see the processors themselves, or the software they are running) that normally have a very specific and dedicated job to do. The size constraints, and dedicated end application nature, rarely warrant the use of a full RTOS implementation - or indeed make the use of a full RTOS implementation possible. FreeRTOS therefore provides the core real time scheduling functionality, inter-task communication, timing and synchronisation primitives only. This means it is more accurately described as a real time kernel, or real time executive. Additional functionality, such as a command console interface, or networking stacks, can then be included with add-on components.

# Why use an RTOS?
You do not need to use an RTOS to write good embedded software. At some point though, as your application grows in size or complexity, the services of an RTOS might become beneficial for one or more of the reasons listed below. These are not absolutes, but opinion. As with everything else, selecting the right tools for the job in hand is an important first step in any project.

In brief:

## Abstract out timing information
The real time scheduler is effectively a piece of code that allows you to specify the timing characteristics of your application - permitting greatly simplified, smaller (and therefore easier to understand) application code.

## Maintainability/Extensibility
Not having the timing information within your code allows for greater maintainability and extensibility as there will be fewer interdependencies between your software modules. Changing one module should not effect the temporal behaviour of another module (depending on the prioritisation of your tasks). The software will also be less susceptible to changes in the hardware. For example, code can be written such that it is temporally unaffected by a change in the processor frequency (within reasonable limits).

## Modularity
Organising your application as a set of autonomous tasks permits more effective modularity. Tasks should be loosely coupled and functionally cohesive units that within themselves execute in a sequential manner. For example, there will be no need to break functions up into mini state machines to prevent them taking too long to execute to completion.

## Cleaner interfaces
Well defined inter task communication interfaces facilitates design and team development.

## Easier testing (in some cases)
Task interfaces can be exercised without the need to add instrumentation that may have changed the behaviour of the module under test.

## Code reuse
Greater modularity and less module interdependencies facilitates code reuse across projects. The tasks themselves facilitate code reuse within a project. For an example of the latter, consider an application that receives connections from a TCP/IP stack - the same task code can be spawned to handle each connection - one task per connection.

## Improved efficiency?
Using FreeRTOS permits a task to block on events - be they temporal or external to the system. This means that no time is wasted polling or checking timers when there are actually no events that require processing. This can result in huge savings in processor utilisation. Code only executes when it needs to. Counter to that however is the need to run the RTOS tick and the time taken to switch between tasks. Whether the saving outweighs the overhead or vice versa is dependent of the application. Most applications will run some form of tick anyway, so making use of this with a tick hook function removes any additional overhead.

## Idle time
It is easy to measure the processor loading when using FreeRTOS.org. Whenever the idle task is running you know that the processor has nothing else to do. The idle task also provides a very simple and automatic method of placing the processor into a low power mode.

## Flexible interrupt handling
Deferring the processing triggered by an interrupt to the task level permits the interrupt handler itself to be very short - and for interrupts to remain enabled while the task level processing completes. Also, processing at the task level permits flexible prioritisation - more so than might be achievable by using the priority assigned to each peripheral by the hardware itself (depending on the architecture being used).

## Mixed processing requirements
Simple design patterns can be used to achieve a mix of periodic, continuous and event driven processing within your application. In addition, hard and soft real time requirements can be met though the use of interrupt and task prioritisation.

## Easier control over peripherals
Gatekeeper tasks facilitate serialisation of access to peripherals - and provide a good mutual exclusion mechanism.

## Etcetera


#Introduction to TASK

The objective of this post is to explain how to launch tasks with the FreeRTOS functions. Since this will introduce some complex concepts, we will start by a very simple example where we will create two tasks that will print some “Hello World” messages and then delete them.

For most of the functionalities that we are going to use in this tutorial, you can check the .h file here. Please check this previous post for an introduction on FreeRTOS and tasks.

#The setup and loop code

We will start our setup function by opening a serial connection, in order to be able to get the output of our testing program. This will be our regular Arduino function.

```
Serial.begin(112500);
delay(1000);
```

Then, we will create the tasks, with a call to the xTaskCreate function. The arguments to this function are the following [1]:

#TaskCode: In this argument, we need to pass a pointer to the function that will implement the task. We will create two functions, TaskOne and TaskTwo, which we will define latter and will be passed in this argument.

#TaskName: The name of the task, in a string. We will use “TaskOne” and “TaskTwo”.

#StackDepth: The size of the stack of the task, specified as the number bytes. There is no simple way of determining the size of the task [2], although some calculations can be made. In this simple example, we will pass a value that is big enough.

#Update: In the original post, it was mentioned that the StackDepth was specified in words, like documented in the FreeRTOS xTaskCreate page. Nonetheless, IDF’s version differs from the original implementation and the stack depth is actually specified in bytes, as indicated in IDF’s documentation. We can also confirm this in IDF’s FreeRTOS task.h file.

#Parameter: Pointer to a parameter that the task function can receive. It needs to be of type (void *) [2]. In this case, for simplicity of the code, we will not use it, so we pass NULL in the argument.

#Priority: Priority of the task. We will create both tasks with the same priority.

TaskHandle: Returns an handle that can be used for latter reference of the task on calls to functions (for example, to delete a task or change its priority) [2]. Also, for this simple example, we are not going to use it, so it will be NULL.

This function returns pdPASS on success or an error code that can be seen here [1]. For now, we will assume that the tasks will be created without any problem, so we are not going to do any error checking. Naturally, for a real case scenario application, we would need to do that to confirm the tasks were created.

So, check bellow the full setup function, already with the calls create the two different tasks.

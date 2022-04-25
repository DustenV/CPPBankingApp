# CPPBankingApp
A sample program created as a basic banking system in the CS210 Programming Languages class.

# What was the objective of the application?
The objective of the Airgead Banking App was to create an application that would allow the user to enter and modify some values for an account, then display a yearly interest report for the account, based on the user's input. These variables included an initial investment amount, an optional monthly deposit amount, an annual interest rate, and the number of years to display in the report.

# What did I do well, and how would I enhance/improve the program?
While developing the application, I kept a strong focus on modularity and readability. Modularity was accomplished by separating most of the program's code from the main function and developing a "display" class, which handled everything internally. This was a difficult task for me at first, not having worked with classes very much in C++, but I was able to get it working well using what I believe are some best practices for C++ coding. The main function would then call the members of this class to perform certain functions in a loop, until the user exited the program. Readability was accomplished through detailed in-line commenting, describing the functionality of most of the code base. This would allow for any programmer outside of myself to understand exactly what each piece of the application is doing, should any enhancements/bug corrections be necessary.

To enhance this program, I would first add an interface. Generally, interfaces are better perceived by users when compared to the default Windows console. By adding an interface and ensuring it is compatible with a variety of operating systems, this program could be pushed from a production standpoint with much more appeal. Another feature I would improve would be the capabilities of the program. I would add the ability to also view a monthly report, and the ability to save preferences for more advanced features in the application. And as a last modification, I would say that more classes could be utilized to more accurately split apart my code by function. During the later part of development, I did see a couple of areas where another class should have been used, rather than the created Display class.

# How will the development of this program assist me in the development of future programs?
The development of this program specifically gave me some insight into the complexities and usefulness of classes, which I believe will be integral in future programming. Having a base knowledge of how to use pointers, call on the members of a class, and define the header file for a class is a set of skills that will be handy.

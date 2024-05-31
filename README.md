#  <p align="center"> ** 📝 get_next_line** </p>                         

<p align="center"> The aim of this 42 School project is to output a text line by line to stdout each time the function is called. </p> 

## 📋 Table of Contents

- [Introduction](#-introduction)
- [Usage](#️-usage)
  - [Requirements](#requirements)
  - [Clone](#clone)
  - [Navigate to the project directory](#navigate-to-the-project-directory)
  - [Use](#use)
- [License](#-license)
- [Contact](#-contact)

## ✨ Introduction
The video below shows a summary of the main concepts necessary to understand the project, such as the terms file descriptor or static variable, or the functions open(), read() and close(). At the end of the video, it is shown schematically how the programme works. 



https://github.com/efrutos/42Madrid_get_next_line/assets/52461710/3087598d-86d5-45c4-a04a-f349ea600803




## 🛠️ Usage
To get "get_next_line" project, follow these steps:

1. **Requeriments**

   The program is implemented in C and requires the GCC compiler along with standard C libraries to execute properly.

   The main function included in this repository is not part of the project itself, but simply a way to test it. Feel free to use your own main function, and don't forget to add the ‘#include “get_next_line.h” header at the top.

    Also, the texts included in the test_gnl file are for testing purposes only, and are the ones used in the main function. Again, feel free to use your own test texts, as well as enter text for stdin.
   
3. **Clone the repository**

  ```bash
  git clone https://github.com/efrutos/42Madrid_get_next_line.git get_next_line
  ```

2. **Navigate to the project directory**

  ```bash
  cd get_next_line
  ```

3. **Use**
 
 Change "xx" with desired buffer size.

  ```bash
  gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx main.c get_next_line.c get_next_line_utils.c && ./a.out
  ```

## 📞 Contact

- Email: [estrella.frutos@gmail.com](mailto:estrella.frutos@gmail.com)


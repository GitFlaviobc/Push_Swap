# Minitalk - Server / Client - .... . .-.. .-.. --- / .-- --- .-. .-.. -..

<h1 name ="content" align = "center">📋 Table of contents</h1>
<p align = "center">
  <a href = "#intro">Intro</a> -
  <a href = "#goal">Goal</a> -
  <a href = "#tec">Tecnology</a> -
  <a href = "#function">Functionality</a> -
  <a href = "#how">How to use</a> -
  <a href = "#test">Tests</a> -
  <a href = "#update">Update</a> -
  <a href = "#author">Author</a>
</p>

<a name="intro"/> <h2> Intro </h2> </a>
- This is a server/client project.
- On this project I learned about PID, signals and bitwise operations.
<p></p>
<a href = "#content">📋</a>

<a name="goal"/> <h2> 🎯 Goal </h2> </a>
- The client will use signals to send a message to the server.
- The server will get the signals and translate to print the message on the terminal.
- Signals SIGUSR1 and SIGUSR2.
- Server will print its PID on the creation.
- Client will send a message to the PID.
- Each character of the message from the client will be translated to 0 and 1 by using the signals.
- The server will receive the signals and translate back to characters and print on the terminal.
- The server and client will send messages between each other to confirm success or errors.
<p></p>
<a href = "#content">📋</a>

<a name="tec"/> <h2> 🛠️ Tecnology </h2> </a>
- Language: C
- VS code
- WSL ubuntu
- Norminette 42 (code norm used by école 42)
<p></p>
<a href = "#content">📋</a>

<a name="function"/> <h2> 📚 Functionality </h2> </a>

⚠️🚧

<p></p>
<a href = "#content">📋</a>

<a name="how"/> <h2> 📖 How to use </h2> </a>

- Clone the repository
```bash
git clone https://github.com/GitFlaviobc/minitalk.git
```
- to create the client and server
```bash
make
```
or
```bash
make all
```
- to delete all obj (.o) files created
```bash
make clean
```
 - to delete all created files
```bash
make fclean
```
 - to delete all files and recreate the client and server
```bash
make re
```
- to run the server
```bash
./server
```
- to run the client
```bash
./client "SERVER PID" message
```
<p></p>
<a href = "#content">📋</a>

<a name="test"/> <h2> 👨‍💻 Tests </h2> </a>
- This can generate random texts: [Text](http://www.dummytextgenerator.com/#jump)
- This can generate Unicode messages: [Unicode](https://texteditor.com/)
- ⚠️For multiple strings don't forget to put between quotes.
<p></p>
<a href = "#content">📋</a>

<a name="update"/> <h2> 🆙 Updates </h2> </a>
- The code I sent to evaluation will be kept the same. Any update will be on the update folder.⚠️🚧
<p></p>
<a href = "#content">📋</a>

<a name="author"/> <h2> 😀 Author </h2> </a>
Name: Flávio Bonini Campos
<p></p>

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/flaviobc88/)
<p></p>
<a href = "#content">📋</a>
<p></p>

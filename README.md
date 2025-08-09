# CPP Server Example

This project is a **small TCP server in C++** that listens on `localhost:8080` and receives a message from a client.  
Its main purpose is to gradually get back into C++ while exploring basic networking (sockets) on macOS.

## Current Features

- Opens a TCP socket
- Listens on port `8080`
- Accepts a client connection
- Reads a message and prints it to the console

---

## Project Structure

```

cpp-server/
│── bin/ # Contains the generated executable
│── build/ # Compilation directory
│── include/ # Header files (.hpp)
│── src/ # Source code (.cpp)
└── CMakeLists.txt

```

## Build and Run

### 1. Generate the project

```bash
mkdir build
cd build
cmake ..
```

### 2. Compile

```bash
cmake --build .
```

### 3. Run the server

```bash
./bin/cpp-server
```

## Testing with a client (example using netcat)

In **another terminal**:

```bash
nc localhost 8080
```

Type a message, then press **Enter** → the server will display the received message.

## Learning Objectives

This project is a **starting point** to:

- Refresh C++ syntax and basic concepts
- Understand how a simple TCP server works
- Evolve step by step: multi-client handling, sending responses, logging, etc.

# CN-code Java Networking & Algorithms - Complete Guide

This repository contains several Java programs demonstrating networking concepts (TCP/UDP client-server communication) and algorithms (CRC, Bellman-Ford).

## Contents
- `EClient.java` & `EServer.java`: Simple TCP client-server communication.
- `UDPClient.java` & `UDPServer.java`: Simple UDP client-server communication.
- `Labman.java`: CRC (Cyclic Redundancy Check) implementation for error detection.
- `Ford.java`: Bellman-Ford algorithm for shortest path in graphs.

## Prerequisites
- Java Development Kit (JDK) installed ([Download here](https://adoptopenjdk.net/)).
- Command Prompt (Windows) or Terminal (Linux/Mac).

## How to Compile
Open your terminal and navigate to the project directory:

Compile all Java files:
```
javac *.java
```

## How to Run

### TCP Client-Server (EClient & EServer)

**Step-by-Step Instructions:**

1. **Open TWO terminal windows** and navigate to the project directory in both.

2. **In Terminal 1 - Start the server:**
   ```
   java EServer
   ```
   You should see: `Server started... waiting for client`

3. **In Terminal 2 - Start the client:**
   ```
   java EClient
   ```
   You should see connection established messages on both terminals.

4. **Communication:**
   - Type messages in the client terminal and press Enter
   - Messages will be echoed back from the server
   - Type "exit" to close the connection

### UDP Client-Server (UDPClient & UDPServer)

**Step-by-Step Instructions:**

1. **Open TWO terminal windows** and navigate to the project directory in both.

2. **In Terminal 1 - Start the server:**
   ```
   java UDPServer
   ```
   You should see: `UDP Server started...`

3. **In Terminal 2 - Start the client:**
   ```
   java UDPClient
   ```
   You should see a prompt to enter messages.

4. **Communication:**
   - Type messages in the client terminal and press Enter
   - Messages will be echoed back from the server
   - Type "bye" to end the connection

### CRC Program
Run:
```
java Labman
```
Follow the prompts to enter message bits and generator.

### Bellman-Ford Algorithm
Run:
```
java Ford
```
Follow the prompts to enter the number of vertices, adjacency matrix, and source vertex.

## Detailed Compilation and Execution Steps

### For EClient-EServer (TCP):

**Terminal 1 (Server):**
```
javac EServer.java
java EServer
```

**Terminal 2 (Client):**
```
javac EClient.java
java EClient
```

### For UDPClient-UDPServer:

**Terminal 1 (Server):**
```
javac UDPServer.java
java UDPServer
```

**Terminal 2 (Client):**
```
javac UDPClient.java
java UDPClient
```

## Notes
- **Always start the server first** before starting the client
- All communication uses localhost (127.0.0.1)
- For UDP programs, type `bye` to end the connection
- Make sure no firewall is blocking the Java applications
- Ensure you're in the correct directory containing the Java files

## Troubleshooting
- If you get "class not found" error, make sure compilation was successful
- If connection fails, check that both programs are running and using the same port
- If ports are busy, you may need to wait a moment or restart your terminal
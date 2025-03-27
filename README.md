# Redis-Like Key-Value Store

This project is a lightweight, Redis-like in-memory key-value store implemented in C. It supports basic commands such as `SET`, `GET`, and `DEL` over a simple TCP connection.

## Features
- In-memory key-value store with expiry functionality.
- Simple command interface using `nc` (netcat).
- Lightweight and easy to use.

## Installation
To compile the project, run the following command:
```bash
gcc -arch arm64 main.c DataStore.c server.c -o Redis
```

## Usage
1. Start the server:
```bash
./Redis
```

2. Open another terminal and use `nc` to connect to the server:
```bash
nc localhost 6379
```

3. Once connected, you can run the following commands:

### Commands
- **SET** `<key>` `<value>` `<expiry>`  
  Example:
  ```
  SET apple fruit 60
  ```

- **GET** `<key>`  
  Example:
  ```
  GET apple
  ```

- **DEL** `<key>`  
  Example:
  ```
  DEL apple
  ```

## Example Interaction
```
SET apple fruit 60
+OK
GET apple
fruit
DEL apple
+OK
GET apple
(nil)
```

## Troubleshooting
If the server does not respond:
- Ensure the server is running.
- Verify the correct port (default is `6379`).
- Use `lsof -i :6379` to confirm the server is listening on the port.

## License
This project is open-source and available for modification and distribution.



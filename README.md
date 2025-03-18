# `🦆 duck-linux-utils`  

**duck-linux-utils** is a collection of lightweight and efficient Linux utilities designed to improve command-line workflows. Each tool in this repository serves a specific purpose, helping users streamline common tasks such as word counting, spinners, and more.  

## 📂 Project Structure  

Each tool is organized into its own directory, with a dedicated README providing detailed usage instructions. Below are the included utilities:  

- **[duck-wc](./@duck-wc/README.md)** – A custom word count utility similar to `wc`, with additional features.  
- **[duck-spinner](./@duck-spinner/README.md)** – A terminal-based spinner animation tool for command-line applications.  

## 🚀 Installation  

To install the utilities, follow these steps:  

```bash
git clone https://github.com/gentelduck/duck-linux-utils.git
cd duck-linux-utils
make
```

## 🛠️ Usage  

After building, the utilities can be used from the `build/` directory:  

```bash
./build/duck-wc -w filename.txt  # Word count
./build/duck-spinner             # Display a loading spinner
```

Each tool has its own README with more details.  

## 🤝 Contributing  

Contributions are welcome! Please check each tool’s respective README for contribution guidelines.  

## 📜 License  

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.  


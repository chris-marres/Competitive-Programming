# Competitive-Programming

# Installation instructions
## Manual Installation
1. Make the scripts executable
```bash
chmod +x scripts/*.sh
```

2. Copy the scripts to the local binary directory. From the base directory of this repository, run the following commands:
```bash
sudo cp scripts/setup.sh /usr/local/bin/setup_script
sudo cp scripts/compile.sh /usr/local/bin/compile_script
sudo cp scripts/run.sh /usr/local/bin/run_script
```

3. Open the file `~/.bash_aliases` and add the following lines to the end:
```bash
nano ~/.bash_aliases
```

```bash
alias setup=". setup_script"
alias compile=". compile_script"
alias run=". run_script"
```
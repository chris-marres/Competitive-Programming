# Competitive-Programming

# Installation instructions
## Manual Installation
1. Modify the `setup.sh` file to point to the correct directory for the `template.cpp`.(Change the path at line 7).

2. Make the scripts executable
```bash
chmod +x scripts/*.sh
```

3. Copy the scripts to the local binary directory. From the base directory of this repository, run the following commands:
```bash
sudo cp scripts/setup.sh /usr/local/bin/setup_script
sudo cp scripts/compile.sh /usr/local/bin/compile_script
sudo cp scripts/run.sh /usr/local/bin/run_script
```

4. Open the file `~/.bash_aliases` and add the following lines to the end:
```bash
nano ~/.bash_aliases
```

```bash
alias setup=". setup_script"
alias compile=". compile_script"
alias run=". run_script"
```

5. Save the file and exit. Then run the following command to reload the aliases:
```bash
source ~/.bash_aliases
```

6. Now you can use the commands `setup`, `compile` and `run` to create a new file(in it's folder), compile and run the code respectively.
Please also note that the `setup` command will automatically redirect you to the folder where the file is created.
No need to cd into it :)
TraceThreat-NRML (Near Realtime Machine Learning)
==============================================================

### License

GNU dependency license under SmartDec decompiler.
Apache 2.0 license under TraceThreat-NRML.

### Schedule implement

Linux/Android run ELF executable file after ART engine reassemblys JAR file to ELF.
We have mapreduce section file of ELF to find system call.
 
|        Details                      |  Status       |
|-------------------------------------|---------------|
| `ELF Map-Reduce with MR4C`          |  Implementing |
| `ELF Diassembly system call`        |  Implementing |


### ML processesing

|        Details                      |  Status       |
|-------------------------------------|---------------|
| `ELF section of systemcall`         |  Implementing |


### Directory structure

|       Details                       |   Meaning          |
|-------------------------------------|--------------------|
| `nc`                                | Diassembly ELF support|
| `filestructure`                     | Read file from system  |


### Command line support build TT-NRML

* Build debug libraries with command line.
	`cmake -DCMAKE_BUILD_TYPE=Debug ..`
* Build release libraries with command line.
        `cmake -DCMAKE_BUILD_TYPE=Release ..`

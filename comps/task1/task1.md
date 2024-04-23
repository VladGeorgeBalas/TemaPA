# Task1

```mermaid
flowchart
    open("Deschide fisierul text")
    read("Citeste datele neprocesate<br/>pentru fiecare echipa ")
    procces("Proceseaza datele")
    add("Adauga la lista inlantuita")
    
    open-->read-->procces-->add
    add-->read
    
    close("Inchide fisierul text")
    add-->close
```
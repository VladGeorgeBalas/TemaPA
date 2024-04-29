```mermaid
flowchart
    MOVE["Parcurge lista"]
    MOVE-->FIND
    FIND["Gaseste elementul cu<br/>scorul cel mai mic"]
    FIND-->DELETE
    DELETE["Sterge elementul gasit"]
    DELETE-->MOVE
```
#!/bin/bash

read -p "Nombre de archivo para norminetear: " FILE

while true
do
    norminette $FILE
    sleep 2
done
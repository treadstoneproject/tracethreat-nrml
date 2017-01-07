#!/bin/bash
echo "Change format file : $1"
astyle --style=kr -A3 --indent-classes  --indent-namespaces  --indent-col1-comments \
        --min-conditional-indent=# --max-instatement-indent=40 --break-blocks \
                --align-pointer=name --align-reference=type $1

# Remove source code original version after formatted soure code.
rm $1.orig

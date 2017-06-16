#!/bin/bash

echo Content-type: text/plain
echo

cd /var/www/cgi-bin

PARAMS=`echo $QUERY_STRING | cut -d\? -f 4`

canal=`echo $PARAMS | cut -d\& -f 1`
numero=`echo $PARAMS | cut -d\& -f 2`
grupo=`echo $PARAMS | cut -d\& -f 3`
funcao=`echo $PARAMS | cut -d\& -f 4`

echo $QUERY_STRING
echo $PARAMS
echo $canal
echo $numero
echo $grupo
echo $funcao

automacao $canal $numero $grupo $funcao

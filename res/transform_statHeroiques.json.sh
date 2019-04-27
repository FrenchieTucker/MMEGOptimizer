#!/bin/bash

sed -r 's/^(( |\t)*)([a-zA-Z]+):/\1"\3":/' -i ${0%/*}/statHeroiques.json

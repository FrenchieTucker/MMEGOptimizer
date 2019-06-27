#!/bin/bash

for key in evoStatHP evoStatAttack evoStatDefense; do
    sed "s/${key}:/\"${key}\":/g" -i ${0%/*}/statsCreaturesBases.json;
done

sed -r 's/"([0-9]*)"/\1/g' -i ${0%/*}/statsCreaturesBases.json

#!/bin/bash

for key in {target,refSku,params,activation,multipliers,type,prob,launchCondition,status}[0-9] spellup; do
    sed "s/${key}/\"&\"/g" -i ${0%/*}/definitionAura.json;
done

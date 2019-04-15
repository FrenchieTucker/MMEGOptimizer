/*
This program helps the user to optimize a glyph's build for an
invocation in the game : Might&Magic : Elemental Guardians
Copyright (C) 2019  Florian LEMEASLE

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef MMEGOPTIMIZER_CTRL_H
#define MMEGOPTIMIZER_CTRL_H

#include <memory>

#include "MMEGOptimizer_wdg.h"

class MMEGOptimizer_ctrl
{
public:
    MMEGOptimizer_ctrl();
    ~MMEGOptimizer_ctrl() = default;

    void show();

private:
    void importerFichier();

    std::unique_ptr<MMEGOptimizer_wdg> m_wdg;
};

#endif // MMEGOPTIMIZER_CTRL_H

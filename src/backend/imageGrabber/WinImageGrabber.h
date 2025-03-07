/*
 * Copyright (C) 2018 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_WINIMAGEGRABBER_H
#define KSNIP_WINIMAGEGRABBER_H

#include "AbstractRectAreaImageGrabber.h"
#include "WinWrapper.h"
#include "src/gui/snippingArea/WinSnippingArea.h"
#include "src/common/platform/HdpiScaler.h"

class WinImageGrabber : public AbstractRectAreaImageGrabber
{
    Q_OBJECT
public:
    explicit WinImageGrabber();
    ~WinImageGrabber() override = default;

protected:
	QRect fullScreenRect() const override;
	QRect activeWindowRect() const override;
	CursorDto getCursorWithPosition() const override;

private:
    WinWrapper *mWinWrapper;
    HdpiScaler mHdpiScaler;
};

#endif //KSNIP_WINIMAGEGRABBER_H

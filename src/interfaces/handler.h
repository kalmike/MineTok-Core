/***********************************************************************
********Copyright (c) 2018-2020 The Bitcoin Core developers*************
**********Copyright (c) 2020 The PIVX Core developers*********************
******************Copyright (c) 2010-2023 Nur1Labs**********************
>Distributed under the MIT software license, see the accompanying
>file COPYING or https://www.opensource.org/licenses/mit-license.php.
************************************************************************/

#ifndef MUBDI_INTERFACES_HANDLER_H
#define MUBDI_INTERFACES_HANDLER_H

#include <memory>

namespace boost {
namespace signals2 {
class connection;
} // namespace signals2
} // namespace boost

namespace interfaces {

//! Generic interface for managing an event handler or callback function
//! registered with another interface. Has a single disconnect method to cancel
//! the registration and prevent any future notifications.
class Handler
{
public:
    virtual ~Handler() {}

    //! Disconnect the handler.
    virtual void disconnect() = 0;
};

//! Return handler wrapping a boost signal connection.
std::unique_ptr<Handler> MakeHandler(boost::signals2::connection connection);

} // namespace interfaces

#endif /* MUBDI_INTERFACES_HANDLER_H */

/**
 * @file
 * @copyright  Copyright 2016 GNSS Sensor Ltd. All right reserved.
 * @author     Sergey Khabarov - sergeykhbr@gmail.com
 * @brief      CPU' register editor.
 */

#pragma once

#include "api_core.h"   // MUST BE BEFORE QtWidgets.h or any other Qt header.
#include "attribute.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

namespace debugger {

class RegWidget : public QWidget {
    Q_OBJECT
public:
    explicit RegWidget(const char *name, QWidget *parent);

signals:
    //void signalChanged(uint64_t idx, uint64_t val);
private slots:
    void slotHandleResponse(AttributeType *resp);

private:
    AttributeType regName_;
    AttributeType cmdRead_;
    QString name_;
    QLineEdit *edit_;
    uint64_t value_;
    uint64_t respValue_;
};

}  // namespace debugger

#pragma once

class Observer {
public:
    virtual void onNotify() = 0;
    virtual ~Observer() = default;
};

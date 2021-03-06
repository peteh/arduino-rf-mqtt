#include <string.h>
#include <iostream>
#include "DipDeviceSwitch.h"

DipDeviceSwitch::DipDeviceSwitch(IRFSender *rfSender, char *code1, char *code2)
    : m_rfSender(rfSender),
      m_resend(3)
{
    size_t s_code1 = strlen(code1);
    m_code1 = new char[s_code1 + 1];
    strcpy(m_code1, code1);

    size_t s_code2 = strlen(code2);
    m_code2 = new char[s_code2 + 1];
    strcpy(m_code2, code2);
}

void DipDeviceSwitch::turnOn()
{
    for (unsigned int i = 0; i < m_resend; i++)
    {
        m_rfSender->switchOn(m_code1, m_code2);
    }
}

void DipDeviceSwitch::turnOff()
{
    for (unsigned int i = 0; i < m_resend; i++)
    {
        m_rfSender->switchOff(m_code1, m_code2);
    }
}
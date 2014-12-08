//#include "axObject.h"
//// #include "axEventManager.h"
//
//axID axObject::_global_id_count = 0;
//
//axObject::axObject() :
//_id(IncrementGlobalIdCount())
//{
//}
//
//axID axObject::IncrementGlobalIdCount()
//{
//	return ++_global_id_count;
//}
//
//void axObject::SetIdForReparenting(const axID& id)
//{
//	_id = id;
//}

#include "axObject.h"
#include "axEventManager.h"

axID axObject::_global_id_count = 0;

void axObject::AddConnection(const axEventId& evtId, axEventFunction fct) const
{
    axEventManager::GetInstance()->AddConnection(_id, evtId, fct);
}

void axObject::PushEvent(const axEventId& evtId, axMsg* msg)
{
    axEventManager::GetInstance()->PushEvent(_id, evtId, msg);
}

void axObject::SetIdForReparenting(const axID& id)
{
	_id = id;
}
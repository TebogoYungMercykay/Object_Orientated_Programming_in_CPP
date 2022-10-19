#include "Calendar.h"

using namespace std;

Calendar::Calendar()
{
    this->head = NULL;
}

Calendar::Calendar(vector<event_data> input)
{
    this->head = NULL;
    for(int i=0; i<input.size(); i++)
    {
        this->createEvent(input[i]);
    }
}

Calendar::~Calendar()
{
    this->clearCalendar();
}

Event* Calendar::getUpcomingEvent(long int now)
{
    if(this->head == NULL)
    {
		return NULL;
    }
	else
	{
		Event* eventPtr = this->head;
        while(eventPtr)
		{
			if(unix_to_string(eventPtr->start) > unix_to_string(now) || eventPtr->start > now)
            {
                return eventPtr;
            }
			eventPtr = eventPtr->next;
		}
        return NULL;
	}
}

vector<Event> Calendar::filterEvents(int* id2, long int* start2, long int* end2, string* type2)
{
    vector<Event> filterEventsVector;
    Event* eventPtr = this->head;
    if(id2 == NULL && start2 == NULL && end2 == NULL && type2 == NULL)
    {
        while(eventPtr)
		{
			Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
            filterEventsVector.push_back(eventDataVec);
			eventPtr = eventPtr->next;
		}
        return filterEventsVector;
    }
    else if(start2 == NULL && end2 == NULL)
    {
        if((id2 != NULL && type2 != NULL))
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->type == *type2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(id2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(type2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->type == *type2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
    }
    else if(start2 == NULL && end2 != NULL)
    {
        if((id2 != NULL && type2 != NULL))
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->type == *type2 && eventPtr->end < *end2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(id2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->end < *end2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(type2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->type == *type2 && eventPtr->end < *end2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else
        {
            while(eventPtr)
            {
                if(eventPtr->end < *end2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
    }
    else if(start2 != NULL && end2 == NULL)
    {
        if((id2 != NULL && type2 != NULL))
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->type == *type2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(id2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(type2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->type == *type2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else
        {
            while(eventPtr)
            {
                if(eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
    }
    else if(start2 != NULL && end2 != NULL)
    {
        if((id2 != NULL && type2 != NULL))
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->type == *type2 && eventPtr->end < *end2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(id2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->id == *id2 && eventPtr->end < *end2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else if(type2 != NULL)
        {
            while(eventPtr)
            {
                if(eventPtr->type == *type2 && eventPtr->end < *end2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
        else
        {
            while(eventPtr)
            {
                if(eventPtr->end < *end2 && eventPtr->start > *start2)
                {
                    Event eventDataVec(eventPtr->start, eventPtr->end, eventPtr->id, eventPtr->type);
                    filterEventsVector.push_back(eventDataVec);
                }
                eventPtr = eventPtr->next;
            }
            return filterEventsVector;
        }
    }
    return filterEventsVector;
}
void Calendar::alterEvent(int id2, long int* end2, string* type2)
{
    if(this->head == NULL || (end2 == NULL && type2 == NULL))
    {
		return;
    }
	else
	{
		Event* eventPtr = this->head;
        while(eventPtr)
		{
			if(eventPtr->id == id2)
            {
				if(end2 != NULL)
                {
                    eventPtr->end = *end2;
                }
                else if(type2 != NULL)
                {
                    eventPtr->type = *type2;
                }
                else
                {
                    continue;
                }
                return;
            }
			eventPtr = eventPtr->next;
		}
	}
}

void Calendar::removeEvent(int id2)
{
    if(this->head == NULL)
    {
        return;
    }
    Event* eventPtr = this->head;
    int index2 = -1;
    int counter = 0;
    bool index = false;
    while(eventPtr)
    {
        if(eventPtr->id == id2)
        {
            index2 = counter;
            index = true;
            break;
        }
        counter++;
        eventPtr = eventPtr->next;
    }
    if(index == false)
    {
		return;
    }
    if(index2 == -1)
    {
        return;
    }
	else if(index2 == 0)
	{
		Event* myPointer = this->head->next;
		this->head->next = NULL;
        if(this->head != NULL)
        {
            delete this->head;
        }
		this->head = myPointer;
        return;
	}
    else
	{
		Event* myPointer = this->head;
		Event* myPrevious = NULL;
		for(int i=0; i<index2; i++)
		{
			myPrevious = myPointer;
			myPointer = myPointer->next;
		}
		myPrevious->next = myPointer->next;
		myPointer->next = NULL;
        if(myPointer != NULL)
        {
            delete myPointer;
        }
        return;
	}
}

void Calendar::createEvent(event_data data)
{
    int counter = 0;
    Event* eventPtr = this->head;
    while(eventPtr && eventPtr->start <= data.start)
    {
        counter++;
        eventPtr = eventPtr->next;
    }

    if(this->head == NULL && counter == 0)
	{
		this->head = new Event(data.start, data.end, data.id, data.type);
        return;
	}
	else if(counter==0)
	{
		Event* myNewNode = new Event(data.start, data.end, data.id, data.type);
		myNewNode->next = this->head;
		this->head = myNewNode;
        return;
	}
	else
	{
		Event* myPointer = this->head;
		for(int i=0; i<counter-1; i++)
		{
			myPointer = myPointer->next;
		}
		Event* myNewNode = new Event(data.start, data.end, data.id, data.type);
		myNewNode->next = myPointer->next;
		myPointer->next = myNewNode;
        return;
	}
}

void Calendar::clearCalendar()
{
    Event* myCurrent = this->head;
	Event* myNext;
	while(myCurrent != NULL)
	{
		myNext = myCurrent->next;
		myCurrent->next = NULL;
		delete myCurrent;
		myCurrent = myNext;
	}
	this->head = NULL;
}

Event* Calendar::getFirstEvent()
{
    return this->head;
}

ostream& operator<<(ostream& out, Calendar& calendar)
{
    if(calendar.head == NULL)
    {
        return out;
    }
    else
    {
        Event* eventPtr = calendar.head;
        int counter = 0;
        while(eventPtr)
		{
            out<<counter<<": ";
            out << *eventPtr;
			if(eventPtr->next!=NULL)
            {
				out<<"\n";
            }
            counter++;
			eventPtr = eventPtr->next;
		}
    }
    return out;
}
#pragma once
#include <stdlib.h>
#include "THeadList.h"
#include <math.h>
#include "TStack.h"
using namespace LIST;
using namespace TSTACK;
using namespace System::Drawing;
class TObject
{
public:
	bool visible;
	virtual void Show (Graphics^ gr) = 0;
	virtual void Hide (Graphics^ gr) = 0;
	virtual void MoveTo (Graphics^ gr, int _x, int _y) = 0;
	virtual void Move (Graphics^ gr, int dx, int dy) = 0;
};
class TPoint : public TObject
{
public:
	int x,y;
public:
	void Show (Graphics^ gr)
	{
		visible=1;
		gr->FillEllipse(Brushes::Black,x,y,3,3);
	}
	void Hide (Graphics^ gr)
	{
		visible=0;
		gr->FillEllipse(Brushes::White,x,y,3,3);
	}
	void Move (Graphics^ gr, int dx, int dy)
	{
		Hide(gr);
		x+=dx; y+=dy;
		Show(gr);
	}
	void MoveTo (Graphics^ gr, int _x, int _y)
	{
		Hide(gr);
		x=_x; y=_y;
		Show(gr);
	}
	TPoint (int _x=0, int _y=0)
	{
		x=_x; y=_y;
	}
};
class TLine : public TPoint
{
public:
	int x2, y2;
	void Show (Graphics^ gr)
	{
		visible=1;
		gr->DrawLine(Pens::Black,x,y,x2,y2);
	}
	void Hide (Graphics^ gr)
	{
		visible=0;
		gr->DrawLine(Pens::White,x,y,x2,y2);
	}
	void MoveTo(Graphics^ gr, int _x, int _y)
	{
		Hide(gr);
		x2+=0; y2+=0;
		x=_x; y=_y;
		Show(gr);
	}
	void MoveLine (Graphics^ gr, int _x, int _y, int _x2, int _y2)
	{
		Hide(gr);
		x2=_x2; y2=_y2;
		x=_x; y=_y;
		Show(gr);
	}

	TLine (int _x=0, int _y=0, int _x2=0, int _y2=0)
	{
		x=_x; y=_y; x2=_x2; y2=_y2;
	}
};
class TChart: public TObject
{
public:
	TObject *begin, *end;
public:
	TObject* DrawRec(Graphics^ gr, TObject* t, int Color)
	{

		TChart* CurLine;
		TPoint *pFp, *pLp;
		if(dynamic_cast<TPoint*>(t)!=NULL)
			return t;
		else
		{
			CurLine = dynamic_cast<TChart*>(t);
			pFp = dynamic_cast<TPoint*>(DrawRec(gr,CurLine->begin, Color));
			pLp = dynamic_cast<TPoint*>(DrawRec(gr,CurLine->end, Color));
			if (pFp&&pLp)
			{
				if(Color==1)
					gr->DrawLine(Pens::Black, pFp->x, pFp->y, pLp->x, pLp->y);
				if(Color==0)
					gr->DrawLine(Pens::White, pFp->x, pFp->y, pLp->x, pLp->y);
				return pFp;
			}
		}
	}
	TChart()
	{
		begin = NULL;
		end = NULL;
	}
	void Show(Graphics^ gr)
	{
		if (this->begin != NULL && this->end != NULL)
			this->DrawRec(gr, this, 1);
		visible=1;
	}
	void Hide (Graphics^ gr)
	{
		if(this->begin!=NULL && this->end!=NULL)
			this->DrawRec(gr, this, 0);
		visible=0;
	}
	void MoveTo (Graphics^ gr, int _x, int _y)
	{

	}
	void Move (Graphics^ gr, int dx, int dy)
	{

	}
	void AddClosestLine(int x1, int y1, int x2, int y2)
	{
		if (begin == NULL && end == NULL)
		{
			begin = new TPoint(x1, y1);
			end = new TPoint(x2, y2);
		}
		else
		{
			TStack<TObject*> stack1;
			TStack<TPoint*> stack2;
			TChart *curr = this;
			TObject *min1, *min2;
			TChart *min;
			int xmin, ymin;
			double difference = 0;
			double differencetmp = 0;
			stack1.push(curr->begin);
			stack1.push(curr->end);
			while (true)
			{
				if (dynamic_cast<TPoint*>(stack1.top()) != NULL)
				{
					stack2.push(dynamic_cast<TPoint*>(stack1.pop()));
				}
				else
				{
					curr = dynamic_cast<TChart*>(stack1.pop());
					stack1.push(curr->begin);
					stack1.push(curr->end);
				}
				if (stack1.IsEmpty())
					break;
			}//в stack2 лежат все точки с которыми надо сравнить
			min1 = stack2.pop();
			difference = sqrt((dynamic_cast<TPoint*>(min1)->x - x1)*(dynamic_cast<TPoint*>(min1)->x - x1)+
							  (dynamic_cast<TPoint*>(min1)->y - y1)*(dynamic_cast<TPoint*>(min1)->y - y1));
			while (!stack2.IsEmpty())
			{
				min2 = stack2.pop();
				if ((differencetmp = sqrt((dynamic_cast<TPoint*>(min2)->x - x1)*(dynamic_cast<TPoint*>(min2)->x - x1)+
										  (dynamic_cast<TPoint*>(min2)->y - y1)*(dynamic_cast<TPoint*>(min2)->y - y1)))<
											difference)
				{
					min1 = min2;
					difference = differencetmp;
				}
			}//теперь в min1 лежит точка с наименьшим отклонением
			xmin = dynamic_cast<TPoint*>(min1)->x;
			ymin = dynamic_cast<TPoint*>(min1)->y;
			delete min1;
			min1 = new TChart();
			dynamic_cast<TChart*>(min1)->begin = new TPoint(xmin, ymin);
			dynamic_cast<TChart*>(min1)->end = new TPoint(x2, y2);
		}
	}
};
class TGroup: TObject
{
public:
	THeadList<TObject*> *objects;
	int quantity;
public:
	void Show (Graphics^ gr)
	{
		for( objects->Reset(); !objects->IsEnd(); objects->GoNext())
		{
			if (objects->pCurrent != NULL)
				objects->pCurrent->value->Show(gr);
			else
				break;
		}
		visible=1;
	}
	void Hide (Graphics^ gr)
	{
		for( objects->Reset(); !objects->IsEnd(); objects->GoNext())
		{
			if (objects->pCurrent != NULL)
				objects->pCurrent->value->Hide(gr);
			else
				break;
		}
		visible=0;
	}
	void MoveTo (Graphics^ gr, int _x, int _y)
	{
		for( objects->Reset(); !objects->IsEnd(); objects->GoNext())
		{
			objects->pCurrent->value->MoveTo(gr, _x, _y);
		}
	}
	void Move (Graphics^ gr, int dx, int dy)
	{
		for( objects->Reset(); !objects->IsEnd(); objects->GoNext())
		{
			objects->pCurrent->value->Move(gr, dx, dy);
		}
	}
	void AddObj (TObject *_object)
	{
		if(dynamic_cast<TPoint*>(_object))
		{
			objects->insFirst(dynamic_cast<TPoint*>(_object));
		}
		else if(dynamic_cast<TLine*>(_object))
		{
			objects->insFirst(dynamic_cast<TLine*>(_object));
		}
		if(dynamic_cast<TChart*>(_object))
		{
			objects->insFirst(dynamic_cast<TChart*>(_object));
		}
		quantity++;
	}



	TGroup()
	{
		objects = new THeadList<TObject*>;
		quantity = 0;
	}
	~TGroup()
	{
		delete objects;
		objects=NULL;
	}
};
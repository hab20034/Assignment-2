#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

class point {
	private:
		float x, y;
		float avgx=0, avgy=0;
	public:
		point ()
		{
			
		}
		point (float a, float b)
		{
			x=a;
			y=b;
		}
		float setx(float X)
		{
			x=X;
		}
		float getx()
		{
			return x;
		}
		float sety(float Y)
		{
			y=Y;
		}
		float gety()
		{
			return y;
		}
		void display ()
		{
				cout<< "(" << getx() << "," << gety() << ")" << endl;			
		}
		point center (point C[], int num)
		{
			for (int i=0; i<num; i++)
			{
				avgx=avgx+C[i].x;
				avgy=avgy+C[i].y;
			}
			avgx=avgx/num;
			avgy=avgy/num;
			point avg;
			avg.setx(avgx);
			avg.sety(avgy);
			return avg;
			
		}
		point closest (point A)
		{
			float x1, y1;
			point p;
			cout << "Enter the coordinates of the point" << endl;
			cin >> x1 >> y1;
			p.setx(x1);
			p.sety(y1);
			if(sqrt(pow((x-p.x), 2)+pow((y-p.y), 2)>pow((A.x-p.x), 2)+pow((A.y-p.y), 2)))
			{
				cout << "The point is closest to cluster B" << endl;
			}
			else
				cout << "The point is closest to cluster A" << endl;	
		}
		void closestrand(point A)
		{
			float x1, y1;
			point p[20];
			srand(time(NULL));
			for (int i=0; i<20; i++)
			{
				p[i].setx(5+(rand() % 100));
				p[i].sety(5+(rand() % 100));
			}
			for (int i=0; i<20; i++)
			{
				if(sqrt(pow((x-p[i].x), 2)+pow((y-p[i].y), 2)>pow((A.x-p[i].x), 2)+pow((A.y-p[i].y), 2)))
			{
				cout << "The point is closest to cluster B" << endl;
			}
			else
				cout << "The point is closest to cluster A" << endl;
			}	
		}
};


int main ()
{
	int n;
	
	point cluster, p[n];
	cout << "Enter the number of points in a cluster" << endl;
	cin >> n; 
	float x, y;
	for (int i=0; i<n; i++)
	{
		cin >> x;
		p[i].setx(x);
		cin >> y;
		p[i].sety(y);
	}
	cluster=cluster.center(p, n);
	cluster.display();
	int n1;
	cout << "Enter the number of points in a cluster" << endl;
	cin >> n1; 
	point cluster1, p1[n1];
	for (int i=0; i<n; i++)
	{
		cin >> x;
		p1[i].setx(x);
		cin >> y;
		p1[i].sety(y);
	}
	cluster1=cluster.center(p1, n1);
	cluster1.closest(cluster);
	for (int i=n; i<200; i++)
	{
		p[i].setx(70+rand()%90);
		p[i].sety(70+rand()%90);
	}
	cluster=cluster.center(p, 200);
	for (int i=n1; i<200; i++)
	{
		p1[i].setx(20+rand()%40);
		p1[i].sety(20+rand()%40);
	}
	cluster1=cluster1.center(p1, 200);
	cluster1.closest(cluster);
	
}







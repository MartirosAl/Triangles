#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

class Point
{
   double x;
   double y;

public:

   Point()
   {
      x = 0;
      y = 0;
   }

   Point(double x_, double y_)
   {
      x = x_;
      y = y_;
   }

   double Get_X()
   {
      return x;
   }

   double Get_Y()
   {
      return y;
   }

   void Set_X(double x_)
   {
      x = x_;
   }

   void Set_Y(double y_)
   {
      y = y_;
   }

   Point operator=(Point& other_)
   {
      x = other_.x;
      y = other_.y;
      return *this;
   }

   Point operator()(double x_, double y_)
   {
      x = x_;
      y = y_;
      return *this;
   }

   void Print_Points()
   {
      printf("(%f, %f)\n", x, y);
   }
};

class Triangle
{
   Point p_one;
   Point p_two;
   Point p_three;

   double s_one_two;
   double s_two_three;
   double s_three_one;

public:

      
   Triangle()
   {
      s_one_two = 0;
      s_two_three = 0;
      s_three_one = 0;
   }

   Triangle(double one_x_, double one_y_, double two_x_, double two_y_, double three_x_, double three_y_)
   {
      p_one(one_x_, one_y_);
      p_two(two_x_, two_y_);
      p_three(three_x_, three_y_);

      s_one_two = sqrt(pow(one_x_ - two_x_, 2) + pow(one_y_ - two_y_, 2));
      s_two_three = sqrt(pow(two_x_ - three_x_, 2) + pow(two_y_ - three_y_, 2));
      s_three_one = sqrt(pow(three_x_ - one_x_, 2) + pow(three_y_ - one_y_, 2));
   }

   bool operator>(Triangle other_)
   {
      if (Area_of_Triangle() > other_.Area_of_Triangle())
         return true;
      else
         return false;
   }

   bool operator>=(Triangle other_)
   {
      if (Area_of_Triangle() >= other_.Area_of_Triangle())
         return true;
      else
         return false;
   }

   Point Get_P_One()
   {
      return p_one;
   }

   Point Get_P_Two()
   {
      return p_two;
   }

   Point Get_P_Three()
   {
      return p_three;
   }

   void Set_P_One(double one_x_, double one_y_)
   {
      p_one.Set_X(one_x_);
      p_one.Set_Y(one_y_);

      s_one_two = sqrt(pow(one_x_ - p_two.Get_X(), 2) + pow(one_y_ - p_two.Get_Y(), 2));
      s_three_one = sqrt(pow(p_three.Get_X() - one_x_, 2) + pow(p_three.Get_Y() - one_y_, 2));
   }   
   
   void Set_P_Two(double two_x_, double two_y_)
   {
      p_one.Set_X(two_x_);
      p_one.Set_Y(two_y_);

      s_one_two = sqrt(pow(p_one.Get_X() - two_x_, 2) + pow(p_one.Get_Y() - two_y_, 2));
      s_two_three = sqrt(pow(two_x_ - p_three.Get_X(), 2) + pow(two_y_ - p_three.Get_Y(), 2));
   }   
   
   void Set_P_Three(double three_x_, double three_y_)
   {
      p_one.Set_X(three_x_);
      p_one.Set_Y(three_y_);

      s_two_three = sqrt(pow(p_two.Get_X() - three_x_, 2) + pow(p_two.Get_Y() - three_y_, 2));
      s_three_one = sqrt(pow(three_x_ - p_one.Get_X(), 2) + pow(three_y_ - p_one.Get_Y(), 2));
   }

   void Print_Triangle()
   {
      p_one.Print_Points();
      p_two.Print_Points();
      p_three.Print_Points();
      printf("%g %g %g\n", s_one_two, s_two_three, s_three_one);
   }

   double Area_of_Triangle()
   {
      double p = (s_one_two + s_two_three + s_three_one)/2;

      double area = sqrt(p * (p - s_one_two) * (p - s_two_three) * (p - s_three_one));

      return area;
   }

   void Move_Triangle(double x_, double y_)
   {
      p_one(p_one.Get_X() + x_, p_one.Get_Y() + y_);
      p_two(p_two.Get_X() + x_, p_two.Get_Y() + y_);
      p_three(p_one.Get_X() + x_, p_three.Get_Y() + y_);
   }

   bool Triangle_Includes_Triangle(Triangle other_)
   {
      if (p_one.Get_X() >= other_.p_one.Get_X() && p_one.Get_Y() >= other_.p_one.Get_Y() &&\
         p_two.Get_X() >= other_.p_two.Get_X() && p_two.Get_Y() >= other_.p_two.Get_Y() &&\
         p_three.Get_X() >= other_.p_three.Get_X() && p_three.Get_Y() >= other_.p_three.Get_Y())
      {
         return true;
      }
      else
         return false;
   }

};

void Menu()
{
   printf("1. Print triangle");
   printf("2. Get Area");
   printf("3. Set triangle");
   printf("4. ");

}



int main()
{
   
   Triangle triangle;
   Triangle triangle2;
   
   while (1)
   {
      system("cls");
      int choice;
      int choice_triangle;
      printf("What do you need?\n");

      Menu();
      printf("> ");
      if (!scanf("%d", &choice))
         return 4;

      system("cls");

      switch (choice)
      {
      case 1:
         printf("Choise: 1st or 2nd triangle\n");
         scanf("%d", choice_triangle);
         if (choice_triangle == 1)
            triangle.Print_Triangle();
         else
            triangle2.Print_Triangle();
         system("pause");
         continue;

      case 2:

   }
   return 0;
}



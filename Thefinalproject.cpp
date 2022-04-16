#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
#include <string.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
void findcenter(vector<Point>c, Mat imagecolor)
{
	int w, z;
	int colorred, colorgreen, colorblue;
	vector<Moments> mu(c.size());
	for (int i = 0; i < c.size(); i++)
	{
		
		mu[i] = moments(c, false);
	}

	///  Get the mass centers:
	vector<Point2f> mc(c.size());
	mc[0] = Point2f(mu[0].m10 / mu[0].m00, mu[0].m01 / mu[0].m00);
	w = mc[0].x;
	z = mc[0].y;
	cout << "[" << w << ":" << z << "]";
	//then find color:
	Vec3b color = imagecolor.at<Vec3b>(Point(w, z));
	colorred = color.val[2];
	colorgreen = color.val[1];
	colorblue = color.val[0];
	/*cout << colorred;
	cout << "  ";
	cout << colorgreen;
	cout << "  ";
	cout << colorblue;
	cout << endl;*/
	if (colorred >= 155 && colorgreen <= 110 && colorblue <= 110)
	{
		cout << " and have Red color";
		cout << endl;

	}
	else if (colorred <= 110 && colorgreen >= 140 && colorblue <= 110)
	{
		cout << " and have Green color ";
		cout << endl;

	}

	else if (colorred <= 110 && colorgreen <= 110 && colorblue >= 155)
	{
		cout << " and have Blue color";
		cout << endl;
	}
	else if (colorred >= 155 && colorgreen >= 155 && colorblue < 110)
	{
		cout << " and have Yellow color";
		cout << endl;
	}
	else if (colorred >= 155 && colorgreen <= 110 && colorblue >= 155)
	{
		cout << "and have Magenta color";
		cout << endl;
	}
	else if (colorred <= 110 && colorgreen >= 155 && colorblue >= 155)
	{
		cout << " and have Cyan color";
		cout << endl;
	}
	else if (colorred <= 110 && colorgreen <= 110 && colorblue <= 110)
	{
		cout << " and have Black color";
		cout << endl;
	}
	else if (colorred >= 155 && colorgreen >= 155 && colorblue >= 155)
	{
		cout << " and have White color";
		cout << endl;
	}
	else {
		cout << " its not a listed color ^_^ ";
		cout << endl;
	}

}
int main()
{ /* the name of groupes:
  Amna Abd-El-Raheem Khdair
  Sana Ahmad Zetawi
  Rawan Hussam Hassoun
	*/
	int r = 1;
	int count;
	//to  find circles in the image

	Mat image1, image2,image3, image4, image5;
	String path;
	cout << "Please Enter Your Path" << endl;
	cin >> path;
	image1 = imread("path");
	cvtColor(image1, image2, COLOR_BGR2GRAY);
	HoughCircles(image2, image4, HOUGH_GRADIENT,
		2, image2.rows / 4, 200, 100);
	image4.convertTo(image5, CV_8U);
	int x[2];

	int colorred, colorgreen, colorblue, y;
	int centers[20];
	int e = 1;
	int f = 0;
	for (int i = 0; i < image5.cols; ++i) {
		int x = image5.data[i * 3];
		int y = image5.data[i * 3 + 1];
		Point center(x, y);
		centers[f] = x;
		centers[e] = y;
		e += 2;
		f += 2;

	}
	int color1, color2;
	int w = 0;
	int q = 1;
	for (int i = 0; i < image5.rows; i++)
	{
		for (int j = 0; j < image5.cols; j++)
		{
			 
			color1 = centers[w];
			color2 = centers[q];

			cout << "shape number : \t " << r << "\t is circle";
			cout << j + 1;
			cout << " its position is ";
			cout << "[";
			cout << color1;
			cout << ":";
			cout << color2;
			cout << "]";
			w += 2;;
			q += 2;
			Point point(image5.at<Vec2b>(i, j));
			Vec3b color = image1.at<Vec3b>(Point(color1, color2));
			colorred = color.val[2];
			colorgreen = color.val[1];
			colorblue = color.val[0];
			if (colorred >= 155 && colorgreen <= 110 && colorblue <= 110)
			{
				cout << " and have Red color";
				cout << endl;

			}
			else if (colorred <= 110 && colorgreen >= 140 && colorblue <= 110)
			{
				cout << " and have Green color ";
				cout << endl;

			}

			else if (colorred <= 110 && colorgreen <= 110 && colorblue >= 155)
			{
				cout << " and have Blue color";
				cout << endl;
			}
			else if (colorred >= 155 && colorgreen >= 155 && colorblue < 110)
			{
				cout << " and have Yellow color";
				cout << endl;
			}
			else if (colorred >= 155 && colorgreen <= 110 && colorblue >= 155)
			{
				cout << "and have Magenta color";
				cout << endl;
			}
			else if (colorred <= 110 && colorgreen >= 155 && colorblue >= 155)
			{
				cout << " and have Cyan color";
				cout << endl;
			}
			else if (colorred <= 110 && colorgreen <= 110 && colorblue <= 110)
			{
				cout << " and have Black color";
				cout << endl;
			}
			else if (colorred >= 155 && colorgreen >= 155 && colorblue >= 155)
			{
				cout << " and have White color";
				cout << endl;
			}
			else {
				cout << " its not a listed color ^_^ ";
				cout << endl;
			}
			r++;
		}
		
	}
	count = r;
	//to find the triangle in the image
	threshold(image2, image3, 230, 255, 0);
	Canny(image3, image3, 0, 50, 5);
	vector<vector<Point> > contours;
	vector<Point> approx;
	findContours(image3.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


	for (int i = 0; i < contours.size(); i++)
	{
		
		approxPolyDP(
			Mat(contours[i]),
			approx,
			arcLength(Mat(contours[i]), true) * 0.04,
			true
		);


		if (fabs(contourArea(contours[i])) < 100 || !isContourConvex(approx))
			continue;

		
		if (approx.size() == 3) {
			count++; cout << "shape number : \t " << count-1 << "\t is triangle";
		cout<< " its position is ";
		findcenter(contours[i], image1);  }
		
	}


	//to find rectangle in the image
	
	Mat edge;
	int count1 = count;
	Canny(image3, edge, 50, 100);
	vector<vector<Point> > contours1;
	vector<Vec4i> hierarchy;
	findContours(image3, contours1, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); ++i)
	{

		approxPolyDP(Mat(contours1[i]), approx, arcLength(Mat(contours1[i]), true) * 0.04, true);
		// Skip small or non-convex objects
		if (fabs(contourArea(contours1[i])) < 100 || !isContourConvex(approx))
			continue;

		if (approx.size() == 4)
		{
			if (count == count1)
			{
				cout << "shape number:\t " << count << "\t is a rectangle";
				cout << " its position is ";
				findcenter(contours1[i], image1);
			}
			else
			{
				cout << "shape number:\t " << count1 << "\tis a rectangle";
				cout << " its position is ";
				findcenter(contours1[i], image1);
			}
			count1++;
		}
		
	}





	return 0;
}

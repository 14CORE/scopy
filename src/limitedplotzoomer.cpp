#include "limitedplotzoomer.h"
#include <qwt_plot.h>

using namespace adiscope;

LimitedPlotZoomer::LimitedPlotZoomer(QWidget *parent, bool doReplot):
    QwtPlotZoomer(parent, doReplot)
{
}

void LimitedPlotZoomer::resetZoom()
{
	QwtPlotZoomer::zoom(0);
}

void LimitedPlotZoomer::zoom(const QRectF &rect)
{
    double xMinValue = plot()->axisInterval(xAxis()).minValue();
    double xMaxValue = plot()->axisInterval(xAxis()).maxValue();

    double x1 = rect.left();
    double x2 = rect.right();

    if (x1 < xMinValue)
            x1 = xMinValue;
    if (x2 > xMaxValue)
            x2 = xMaxValue;

    QwtPlotZoomer::zoom(QRectF(QPointF(x1,rect.top()),
			QPointF(x2, rect.bottom())));
}

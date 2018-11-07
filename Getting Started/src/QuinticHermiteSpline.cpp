/*
 * QuinticHermiteSpline.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: leeja
 */

#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>

class QuinticSpline {
	static constexpr double m_HALF_DRIVE_WIDTH { 0.2 };
	double m_px0, m_px1, m_vx0, m_vx1, m_ax0, m_ax1;
	double m_py0, m_py1, m_vy0, m_vy1, m_ay0, m_ay1;
	std::array<double, 6> m_xEquation { };
	std::array<double, 6> m_yEquation { };
	std::array<double, 6> m_xDerEquation { };
	std::array<double, 6> m_yDerEquation { };
	std::array<double, 6> m_xDoubleDerEquation { };
	std::array<double, 6> m_yDoubleDerEquation { };

public:
	QuinticSpline(double px0, double px1, double vx0, double vx1, double ax0, double ax1, double py0, double py1, double vy0, double vy1, double ay0, double ay1) {
		m_px0 = px0;
		m_px1 = px1;
		m_vx0 = vx0;
		m_vx1 = vx1;
		m_ax0 = ax0;
		m_ax1 = ax1;
		m_py0 = py0;
		m_py1 = py1;
		m_vy0 = vy0;
		m_vy1 = vy1;
		m_ay0 = ay0;
		m_ay1 = ay1;
		generateEquations();
		generateDerEquations();
		generateDoubleDerEquations();
	}

private:
	void generateEquations() {
		double term0 = -6 * m_px0 - 3 * m_vx0 - 0.5 * m_ax0 + 0.5 * m_ax1 - 3 * m_vx1 + 6 * m_px1;
		double term1 = 15 * m_px0 + 8 * m_vx0 + 1.5 * m_ax0 - m_ax1 + 7 * m_vx1 - 15 * m_px1;
		double term2 = -10 * m_px0 - 6 * m_vx0 - 1.5 * m_ax0 + 0.5 * m_ax1 - 4 * m_vx1 + 10 * m_px1;
		double term3 = 0.5 * m_ax0;
		double term4 = m_vx0;
		double term5 = m_px0;
		m_xEquation = { term0, term1, term2, term3, term4, term5 };

		term0 = -6 * m_py0 - 3 * m_vy0 - 0.5 * m_ay0 + 0.5 * m_ay1 - 3 * m_vy1 + 6 * m_py1;
		term1 = 15 * m_py0 + 8 * m_vy0 + 1.5 * m_ay0 - m_ay1 + 7 * m_vy1 - 15 * m_py1;
		term2 = -10 * m_py0 - 6 * m_vy0 - 1.5 * m_ay0 + 0.5 * m_ay1 - 4 * m_vy1 + 10 * m_py1;
		term3 = 0.5 * m_ay0;
		term4 = m_vy0;
		term5 = m_py0;
		m_yEquation = { term0, term1, term2, term3, term4, term5 };
	}

	void generateDerEquations() {
		double term0 = 0;
		double term1 = 5 * m_xEquation.at(0);
		double term2 = 4 * m_xEquation.at(1);
		double term3 = 3 * m_xEquation.at(2);
		double term4 = 2 * m_xEquation.at(3);
		double term5 = m_xEquation.at(4);
		m_xDerEquation = { term0, term1, term2, term3, term4, term5 };

		term0 = 0;
		term1 = 5 * m_yEquation.at(0);
		term2 = 4 * m_yEquation.at(1);
		term3 = 3 * m_yEquation.at(2);
		term4 = 2 * m_yEquation.at(3);
		term5 = m_yEquation.at(4);
		m_yDerEquation = { term0, term1, term2, term3, term4, term5 };
	}

	void generateDoubleDerEquations() {
		double term0 = 0;
		double term1 = 0;
		double term2 = 4 * m_xDerEquation.at(1);
		double term3 = 3 * m_xDerEquation.at(2);
		double term4 = 2 * m_xDerEquation.at(3);
		double term5 = m_xDerEquation.at(4);
		m_xDoubleDerEquation = { term0, term1, term2, term3, term4, term5 };

		term0 = 0;
		term1 = 0;
		term2 = 4 * m_yDerEquation.at(1);
		term3 = 3 * m_yDerEquation.at(2);
		term4 = 2 * m_yDerEquation.at(3);
		term5 = m_yDerEquation.at(4);
		m_yDoubleDerEquation = { term0, term1, term2, term3, term4, term5 };
	}

	double getArcLenVal(bool isAdding, double t) {
		double xPart1 = plugInEquation(1, true, t);
		double xPart2 = 0.5 * pow(pow(m_HALF_DRIVE_WIDTH, 2) / (1 + pow(plugInEquation(1, true, t) / plugInEquation(1, false, t), 2)), -0.5);
		double xPart3 = -1 * pow(m_HALF_DRIVE_WIDTH, 2) * pow(1 + pow(plugInEquation(1, true, t) / plugInEquation(1, false, t), 2), -2);
		double xPart4 = 2 * (plugInEquation(1, true, t) / plugInEquation(1, false, t));
		double xPart5 = (plugInEquation(2, true, t) * plugInEquation(1, false, t) - plugInEquation(1, true, t) * plugInEquation(2, false, t)) / pow(plugInEquation(1, false, t), 2);
		double finalX = 0;
		if (isAdding) {
			finalX = xPart1 + xPart2 * xPart3 * xPart4 * xPart5;
		} else {
			finalX = xPart1 - xPart2 * xPart3 * xPart4 * xPart5;
		}

		double yPart1 = plugInEquation(1, false, t);
		double yPart2 = -1 * xPart5;
		double yPart3 = sqrt(pow(m_HALF_DRIVE_WIDTH, 2) / (1 + pow(plugInEquation(1, true, t) / plugInEquation(1, false, t), 2)));
		double yPart4 = -1 * (plugInEquation(1, true, t) / plugInEquation(1, false, t));
		double yPart5 = xPart2 * xPart3 * xPart4 * xPart5;
		double finalY = 0;
		if (isAdding) {
			finalY = yPart1 + (yPart2 * yPart3 + yPart4 * yPart5);
		} else {
			finalY = yPart1 - (yPart2 * yPart3 + yPart4 * yPart5);
		}

		return sqrt(pow(finalX, 2) + pow(finalY, 2));
	}

public:

	double getHalfDriveWidth() {
		return m_HALF_DRIVE_WIDTH;
	}

	std::array<double, 6> getEquation(int der, bool isX) {
		if (der == 0) {
			if (isX) {
				return m_xEquation;
			} else {
				return m_yEquation;
			}
		} else if (der == 1) {
			if (isX) {
				return m_xDerEquation;
			} else {
				return m_yDerEquation;
			}
		} else {
			if (isX) {
				return m_xDoubleDerEquation;
			} else {
				return m_yDoubleDerEquation;
			}
		}
	}

	double getPos(bool is0, bool isX) {
		if (is0) {
			if (isX) {
				return m_px0;
			} else {
				return m_py0;
			}
		} else {
			if (isX) {
				return m_px1;
			} else {
				return m_py1;
			}
		}
	}

	double getDer(bool isFirst, bool is0) {
		if (isFirst) {
			if (is0) {
				return m_vy0 / m_vx0;
			} else {
				return m_vy1 / m_vx1;
			}
		} else {
			if (is0) {
				return (m_vx0 * m_ay0 - m_ax0 * m_vy0) / pow(m_vx0, 3);
			} else {
				return (m_vx1 * m_ay1 - m_ax1 * m_vy1) / pow(m_vx1, 3);
			}
		}
	}

	double plugInEquation(int der, bool isX, double t) {
		std::array<double, 6> equation = getEquation(der, isX);
		double term0 = equation.at(0) * pow(t, 5);
		double term1 = equation.at(1) * pow(t, 4);
		double term2 = equation.at(2) * pow(t, 3);
		double term3 = equation.at(3) * pow(t, 2);
		double term4 = equation.at(4) * t;
		double term5 = equation.at(5);
		return term0 + term1 + term2 + term3 + term4 + term5;
	}

	double getSlope(double t) {
		return plugInEquation(1, false, t) / plugInEquation(1, true, t);
	}

	double getNormalSlope(double t) {
		return -1 / getSlope(t);
	}

	double getWheelX(double t) {
		double slope = getNormalSlope(t);
		return sqrt(pow(m_HALF_DRIVE_WIDTH, 2) / (1 + pow(slope, 2)));
	}

	double getWheelY(double t) {
		return getNormalSlope(t) * getWheelX(t);
	}

	double getArcLen(bool isAdding, double t1, double t2) {
		constexpr int NUM_STEPS = 20;
		double step = (t2 - t1) / NUM_STEPS;
		if (t1 == 0) {
			t1 = step / 1000000;
			step = (t2 - t1) / NUM_STEPS;
		}
		std::array<double, NUM_STEPS+1> arcLenVals { };
		for (int i = 0; i <= NUM_STEPS; i++) {
			arcLenVals.at(i) = getArcLenVal(isAdding, t1 + i * step);
		}
		double arcLength = 0;
		for (int i = 1; i <= NUM_STEPS; i++) {
			arcLength += ((arcLenVals.at(i-1) + arcLenVals.at(i)) / 2) * step;
		}
		return arcLength;
	}
};

int main() {
	double px0 = 0;
	double px1 = 1;
	double vx0 = 1;
	double vx1 = 0;
	double ax0 = 0;
	double ax1 = 0;

	double py0 = 0;
	double py1 = 1;
	double vy0 = 0;
	double vy1 = 1;
	double ay0 = 0;
	double ay1 = 0;

	QuinticSpline quinticSpline(px0, px1, vx0, vx1, ax0, ax1, py0, py1, vy0, vy1, ay0, ay1);

	std::array<double, 6> xEquation = quinticSpline.getEquation(0, true);
	std::cout << "f(t) = " << xEquation.at(0) << "t^5 + " << xEquation.at(1) << "t^4 + " << xEquation.at(2) << "t^3 + " << xEquation.at(3) << "t^2 + " << xEquation.at(4) << "t + " << xEquation.at(5) << '\n';

	std::array<double, 6> yEquation = quinticSpline.getEquation(0, false);
	std::cout << "g(t) = " << yEquation.at(0) << "t^5 + " << yEquation.at(1) << "t^4 + " << yEquation.at(2) << "t^3 + " << yEquation.at(3) << "t^2 + " << yEquation.at(4) << "t + " << yEquation.at(5) << '\n';

	std::cout << "position 0: (" << quinticSpline.getPos(true, true) << ", " << quinticSpline.getPos(true, true) << ")   ";
	std::cout << "position 1: (" << quinticSpline.getPos(false, true) << ", " << quinticSpline.getPos(false, false) << ")\n";

	std::cout << "1st derivative 0: " << quinticSpline.getDer(true, true) << "   ";
	std::cout << "1st derivative 1: " << quinticSpline.getDer(true, false) << '\n';

	std::cout << "2nd derivative 0: " << quinticSpline.getDer(false, true) << "   ";
	std::cout << "2nd derivative 1: " << quinticSpline.getDer(false, false) << '\n';

	std::array<double, 6> xDerEquation = quinticSpline.getEquation(1, true);
	std::cout << "x'(t) = " << xDerEquation.at(0) << ' ' << xDerEquation.at(1) << ' ' << xDerEquation.at(2) << ' ' << xDerEquation.at(3) << ' ' << xDerEquation.at(4) << ' ' << xDerEquation.at(5) << '\n';

	std::array<double, 6> yDerEquation = quinticSpline.getEquation(1, false);
	std::cout << "y'(t) = " << yDerEquation.at(0) << ' ' << yDerEquation.at(1) << ' ' << yDerEquation.at(2) << ' ' << yDerEquation.at(3) << ' ' << yDerEquation.at(4) << ' ' << yDerEquation.at(5) << '\n';

	constexpr int NUM_STEPS = 50;

	std::array<double, NUM_STEPS> velPropL { };
	std::array<double, NUM_STEPS> velPropR { };

	double prevPower1;
	double prevPower2;

	double step = 1.0 / NUM_STEPS;
	for (double t = 0; t <= 1 + step/10; t += step) {
		double xPosC = quinticSpline.plugInEquation(0, true, t);
		double yPosC = quinticSpline.plugInEquation(0, false, t);
		double xPos1 = xPosC + quinticSpline.getWheelX(t);
		double yPos1 = yPosC + quinticSpline.getWheelY(t);
		double xPos2 = xPosC - quinticSpline.getWheelX(t);
		double yPos2 = yPosC - quinticSpline.getWheelY(t);

		if (quinticSpline.getSlope(t) == 0) {
			yPos1 = quinticSpline.getHalfDriveWidth();
			yPos2 = -1 * quinticSpline.getHalfDriveWidth();
		}

		double len1 = quinticSpline.getArcLen(true, t-step, t);
		double len2 = quinticSpline.getArcLen(false, t-step, t);

		if (quinticSpline.getSlope(t) > 0) {
			double temp = len1;
			len1 = len2;
			len2 = temp;
		}

		double power1 = len1 > len2 ? 1 : len1/len2;
		double power2 = len2 > len1 ? 1 : len2/len1;
		power1 /= 3.58;
		power2 /= 3.58;

		if (t > 0) {
			velPropL[static_cast<int>(t*NUM_STEPS-0.9)] = power1;
			velPropR[static_cast<int>(t*NUM_STEPS-0.9)] = power2;
		}

		std::cout << std::fixed << std::setprecision(3);
		std::cout << "t = " << t << ": " << quinticSpline.getSlope(t) << "   ";
		std::cout << "C: (" << xPosC << ", " << yPosC << ")   ";
		std::cout << "1: (" << xPos1 << ", " << yPos1 << ")";
		if (t != 0) {
			std::cout << " len1: " << len1;
		}
		std::cout << "   2: (" << xPos2 << ", " << yPos2 << ")";
		if (t != 0) {
			std::cout << " len2: " << len2 << ' ';
		}

		if (t != 0) {
			double powerDiff1 = power1 - prevPower1;
			double powerDiff2 = power2 - prevPower2;
			std::cout << "powerDiffs: " << powerDiff1 << ' ' << powerDiff2;
		}

		std::cout << '\n';

		prevPower1 = power1;
		prevPower2 = power2;
	}

	for (int i = 0; i < NUM_STEPS; i++) {
		std::cout << (i+1) / 50.0 << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < NUM_STEPS; i++) {
		std::cout << velPropL.at(i) << ' ';
	}
	std::cout << '\n';
	for (int i = 0; i < NUM_STEPS; i++) {
		std::cout << velPropR.at(i) << ' ';
	}

	return 0;
}

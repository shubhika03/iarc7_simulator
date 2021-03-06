#include "common.h"

Common::Common()
{

}

void Common::setQuadPose(Pose p)
{
  quadPose = p;
}

Pose Common::getQuadPose()
{
  return quadPose;
}

void Common::setgBot0Pose(Pose p)
{
  gBot0Pose = p;
}

Pose Common::getgBot0Pose()
{
  return gBot0Pose;
}

void Common::setgBot1Pose(Pose p)
{
  gBot1Pose = p;
}

Pose Common::getgBot1Pose()
{
  return gBot1Pose;
}

void Common::setgBot5Pose(Pose p)
{
  gBot5Pose = p;
}

Pose Common::getgBot5Pose()
{
  return gBot5Pose;
}

void Common::quatToEuler(double q_w, double q_x, double q_y, double q_z, double& yaw, double& pitch, double& roll)
{
  const double w2 = q_w*q_w;
  const double x2 = q_x*q_x;
  const double y2 = q_y*q_y;
  const double z2 = q_z*q_z;
  const double unitLength = w2 + x2 + y2 + z2;    // Normalised == 1, otherwise correction divisor.
  const double abcd = q_w*q_x + q_y*q_z;
  const double eps = 1e-7;    // TODO: pick from your math lib instead of hardcoding.
  const double pi = 3.14159265358979323846;   // TODO: pick from your math lib instead of hardcoding.
  if (abcd > (0.5-eps)*unitLength)
  {
    yaw = 2 * atan2(q_y, q_w);
    pitch = pi;
    roll = 0;
  }
  else if (abcd < (-0.5+eps)*unitLength)
  {
    yaw = -2 * ::atan2(q_y, q_w);
    pitch = -pi;
    roll = 0;
  }
  else
  {
    const double adbc = q_w*q_z - q_x*q_y;
    const double acbd = q_w*q_y - q_x*q_z;
    yaw = ::atan2(2*adbc, 1 - 2*(z2+x2));
    pitch = ::asin(2*abcd/unitLength);
    roll = ::atan2(2*acbd, 1 - 2*(y2+x2));
  }
}

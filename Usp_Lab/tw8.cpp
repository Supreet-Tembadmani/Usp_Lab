  #include "ns3/netanim-module.h"

  AnimationInterface anim("first, xml");
  AsciiTraceHelper ascii;
  point.EnableAsciiAll(ascii.CreateFileStream("first.tr"));
  pointToPoint.EnablePcapAll("first");

#ifndef __MDFN_CDACCESS_PHYSICAL_H
#define __MDFN_CDACCESS_PHYSICAL_H

//
// This class's methods are NOT re-entrant!
//

// Don't include <cdio.h> here, else it will pollute with its #define's.

class CDAccess_Physical : public CDAccess
{
 public:

 CDAccess_Physical(const std::string& path);
 virtual ~CDAccess_Physical();

 virtual void Read_Raw_Sector(uint8 *buf, int32 lba);

 virtual void Read_TOC(CDUtility::TOC *toc);

 virtual bool Is_Physical(void) throw();

 virtual void Eject(bool eject_status);
 private:

 void *p_cdio;

 void DetermineFeatures(void);
 void ReadPhysDiscInfo(unsigned retry);

 void PreventAllowMediumRemoval(bool prevent);

 CDUtility::TOC PhysTOC;

 // TODO: 1-bit per sector on the physical CD.  If set, don't read that sector.
 uint8 SkipSectorRead[65536];
};

#endif

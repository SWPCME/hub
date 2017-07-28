#include "hub_ctl.hpp"
#include "gda/gda_ctl.hpp"
#include "gda/gda_corectl.hpp"
#include "gda/gda_driversctl.hpp"
#include "gdal/gdal.h"
#include "stdlib.h"

int main()
{
    CHubCtl *hubCtl = CHubCtl::Hub();
    hubCtl->Register(HubMGda);
    CGdaCtl *gdaCtl = (CGdaCtl *) hubCtl->Module(HubMGda);
    CGdaCoreCtl *coreCtl = gdaCtl->Core();
    GDALAllRegister();
    OGRRegisterAll();
    CGdaDriversCtl *driversCtl = coreCtl->Drivers();
    /* OGRCleanupAll(); */
    /* OGRRegisterAll(); */
    OGRSFDriverH driver;
    driver = OGRGetDriver(0);
    OGRRegisterDriver(driver);
    int i = OGRGetDriverCount();
    printf("%s\n", OGR_Dr_GetName(driver));
    printf("%d\n", i);
    return 0;
}

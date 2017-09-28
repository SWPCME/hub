/******************************************************************************
 * $Id: TestJavaCtl.java 2017-09 $
 *
 * Project:  Test of java.
 * Purpose:  Test java control.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017.08 ~ 2017 Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

import whub.*;

public class TestJavaCtl
{
    public static void main(String[] aArgs)
    {
        System.out.println(System.getProperty("java.library.path"));

        CHubCtl hubCtl = CHubCtl.Hub();
        hubCtl.RegisterAll();

        COgrCtl ogrCtl = hubCtl.Ogr();
        ogrCtl.RegisterAll();
        COgrDriverCtl drShpCtl = ogrCtl.Driver(OgrFormatCodeT.OgrFormatShp);

        // Create shp file.
        UStringT drShpName = new UStringT("/home/swpcme/tmp/x");
        // UStringT drShpName = new UStringT("./test");
        COgrDatasrcCtl dsShpCtl = drShpCtl.Create(drShpName);
        UStringT dsShpName = new UStringT("test_create.shp");
        // COgrLayerCtl layerShpCtl = dsShpCtl.Create(dsShpName);

        // Load shp file.
        UStringT drLoadShpName = new UStringT("/home/swpcme/file/source/swpcme/hub/data/geojson/tmp/forest_shp.shp");
        // UStringT drLoadShpName = new UStringT("test/test_load.shp");
        COgrDatasrcCtl dsLoadShpCtl = drShpCtl.Load(drLoadShpName);
        COgrLayerCtl layerLoadShpCtl = dsLoadShpCtl.Load(0);
        COgrFeaturesCtl featuresLoadShpCtl = layerLoadShpCtl.Features();
        COgrFeatureCtl featureLoadShpCtl = featuresLoadShpCtl.Load(1);
        COgrFieldCtl fieldLoadShpCtl = featureLoadShpCtl.Field();
        UStringT valueFieldLoadShp = new UStringT();
        fieldLoadShpCtl.Value(valueFieldLoadShp, 1);
        valueFieldLoadShp.ToConsole();

        drShpCtl.CloseAll();

        UStringT str = new UStringT("Test");
        str.ToConsole();
    }
}

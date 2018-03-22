/******************************************************************************
 * $Id: TestOgr.java 2017-12 $
 *
 * Project:  Test.
 * Purpose:  Test ogr.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2017.12 ~ 2017 Weiwei Huang
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

package TestJava;
import whub.*;

public class TestOgr
{
    private COgrCtl mOgr;

    public void Test()
    {
        CHubCtl hubCtl = CHubCtl.Hub();
        CHubModuleCtl module = hubCtl.RegModule();
        module.Register(HubCodeT.HubMOgr);

        mOgr = module.Ogr();
        TestWrite();
        // TestRead();
        hubCtl.DeregModule(module);
    }

    public void TestWrite()
    {
        mOgr.Register(OgrFormatCodeT.OgrFormatShp);
        COgrDriverCtl dr = mOgr.Driver(OgrFormatCodeT.OgrFormatShp);
        UStringT dsName = new UStringT("../../../data/core/ogr/t_write");
        COgrDatasrcCtl ds = dr.Create(dsName);
        UStringT layerName = new UStringT("linestring");
        COgrLayerCtl layer = ds.Create(layerName);
        COgrFeaturesCtl features = layer.Features();
        COgrFeatureCtl feature = features.Create();
        COgrGeomsCtl geoms = feature.Geoms();
        COgrGeomCtl geom = geoms.Create(OgrGeomTCodeT.OgrGeomTLineString);
        COgrGeomVertex vertex = geom.Vertex();
        BMathCsC2dT pt = new BMathCsC2dT();
        pt.SetAll(3.1, 4.5);
        vertex.AddPoint2D(pt);
        pt.SetAll(5.3, 7.6);
        vertex.AddPoint2D(pt);
        pt.SetAll(-10.2, -3.9);
        vertex.AddPoint2D(pt);
        geoms.Set(geom);
        geoms.CloseAll();
        features.CloseAll();
        features.Add(feature);
        // dr.CloseAll();
    }

    public void TestRead()
    {
        mOgr.Register(OgrFormatCodeT.OgrFormatShp);
        COgrDriverCtl dr = mOgr.Driver(OgrFormatCodeT.OgrFormatShp);

        // Load shp file.
        UStringT dsName = new UStringT("/home/swpcme/file/source/swpcme/hub/data/core/ogr/t_write/linestring.shp");
        COgrDatasrcCtl ds = dr.Load(dsName);
        COgrLayerCtl layer = ds.Load(0);
        COgrFeaturesCtl features = layer.Features();
        COgrFeatureCtl feature = features.Load(0);
        COgrFieldCtl field = feature.Field();
        UStringT value = new UStringT();
        field.Value(value, 1);
        value.ToConsole();
        COgrGeomsCtl geoms = feature.Geoms();
        UStringT val = new UStringT("Geom\n");
        val.ToConsole();
        COgrGeomCtl geom = geoms.Load();
        COgrGeomVertex geomV = geom.Vertex();
        BMathCsC2dT pt = new BMathCsC2dT();
        geomV.Point2D(pt, 0);

        // dr.CloseAll();
    }
}

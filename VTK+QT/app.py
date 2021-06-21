#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
"""
import os
import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMainWindow, QApplication
# from slider import Ui_MainWindow
from vtk.qt.QVTKRenderWindowInteractor import QVTKRenderWindowInteractor
import vtk
from vtk import *
from GUI2 import Ui_MainWindow
dataDir = 'Head/vhf'
surfaceExtractor = vtk.vtkContourFilter()

volumeColor = vtk.vtkColorTransferFunction()
  

    
class AppWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.IsoSlider.valueChanged.connect(self.slider_SLOT)
        self.show()
        self.btnDciom=self.ui.DicomBTN
        self.btnIso=self.ui.SurfaceBTN
        self.btnRay=self.ui.RayBTN
        self.btnIso.clicked.connect(self.vtk_renderingsISO)  
        self.btnRay.clicked.connect(self.VTK_rendringRay)
        self.btnDciom.clicked.connect(self.VTK_rendringDCIOM)
        self.sliderRay=self.ui.TransferSlider
        self.sliderRay.setRange(0,5)
        # self.sliderRay.sliderReleased.connect(self.VTK_rendringRay)
        self.sliderRay.valueChanged.connect(self.UpdateTransfer)
        # self.sliderRay.valueChanged.connect(self.Update)
        self.Browser=self.ui.pushButton
        self.Browser.clicked.connect(self.Browse)
        # slider=self.ui.horizontalSlider
        # slider.setRange(0,10)
        # value=slider.value()
     


    def slider_SLOT(self):
        val=self.ui.IsoSlider.value()
        surfaceExtractor.SetValue(0, val)
        self.renWin.Render()
   
    def UpdateTransfer(self):
        val4=self.sliderRay.value()
        print("hi")
        print(val4)
        volumeColor.AddRGBPoint(0,  val4* 0.64, 0.0, 0.0)
        volumeColor.AddRGBPoint(500, val4* 1.0, val4*1.0,val4* 0.3)
        volumeColor.AddRGBPoint(1000,val4* 1.0, val4*0.5,val4* 0.3)
        volumeColor.AddRGBPoint(1150, val4*1.0, val4*1.0,val4* 0.9)
        self.renWin.Render()
    # def Update(self):
    
    #     if self.val3>0:
    #         iren.update()
            
    def Browse (self):
        FileName=QtWidgets.QFileDialog.getExistingDirectory(self)
        head ,tail=os.path.split(FileName)
        self.Browser.setText(tail)
        if FileName:
            self.filename=FileName
        else:
            self.Browser.setText("Browse a file")
            return
    def vtk_renderingsISO(self):
        
        ren = vtk.vtkRenderer()
        self.renWin = vtk.vtkRenderWindow()
        self.renWin.AddRenderer(ren)
        iren = vtk.vtkRenderWindowInteractor()
        iren.SetRenderWindow(self.renWin)


        aRenderer = vtk.vtkRenderer()
        self.renWin.AddRenderer(aRenderer)


        reader = vtk.vtkDICOMImageReader()   
        reader.SetDataByteOrderToLittleEndian()
        try:
            self.filename
        except:
            return    
        reader.SetDirectoryName(self.filename)
        reader.Update()

   
        surfaceExtractor.SetInputConnection(reader.GetOutputPort())
        surfaceExtractor.SetValue(0, 500)
        surfaceNormals = vtk.vtkPolyDataNormals()
        surfaceNormals.SetInputConnection(surfaceExtractor.GetOutputPort())
        surfaceNormals.SetFeatureAngle(60.0)
        surfaceMapper = vtk.vtkPolyDataMapper()
        surfaceMapper.SetInputConnection(surfaceNormals.GetOutputPort())
        surfaceMapper.ScalarVisibilityOff()
        surface = vtk.vtkActor()
        surface.SetMapper(surfaceMapper)
        
        aCamera = vtk.vtkCamera()
        aCamera.SetViewUp(0, 0, -1)
        aCamera.SetPosition(0, 1, 0)
        aCamera.SetFocalPoint(0, 0, 0)
        aCamera.ComputeViewPlaneNormal()
        
        aRenderer.AddActor(surface)
        aRenderer.SetActiveCamera(aCamera)
        aRenderer.ResetCamera()
        
        aRenderer.SetBackground(0, 0, 0)
        
        aRenderer.ResetCameraClippingRange()
        
        # Interact with the data.
        iren.Initialize()
        self.renWin.Render()
        iren.Start()
        iren.show()
     



    def VTK_rendringDCIOM(self):
        ren = vtk.vtkRenderer()
        renWin = vtk.vtkRenderWindow()
        renWin.AddRenderer(ren)
        iren = vtk.vtkRenderWindowInteractor()
        iren.SetRenderWindow(renWin)




        reader = vtk.vtkDICOMImageReader()   
        reader.SetDataByteOrderToLittleEndian()
        try:
            self.filename
        except:
            return    
        reader.SetDirectoryName(self.filename)
        reader.Update()


        imageViewer = vtk.vtkImageViewer2()
        imageViewer.SetInputConnection(reader.GetOutputPort())
        renderWindowInteractor = vtk.vtkRenderWindowInteractor()
        imageViewer.SetupInteractor(renderWindowInteractor)
        imageViewer.Render()
        imageViewer.GetRenderer().ResetCamera()
        imageViewer.Render()
        renderWindowInteractor.Start()


    def VTK_rendringRay(self):
        ren = vtk.vtkRenderer()
        self.renWin = vtk.vtkRenderWindow()
        self.renWin.AddRenderer(ren)
        iren = vtk.vtkRenderWindowInteractor()
        iren.SetRenderWindow(self.renWin)



        reader = vtk.vtkDICOMImageReader()   
        reader.SetDataByteOrderToLittleEndian()
        try:
            self.filename
        except:
            return    
        reader.SetDirectoryName(self.filename)
        reader.Update()


    # Trying Volume rendring
        volumeScalarOpacity = vtk.vtkPiecewiseFunction()
        volumeScalarOpacity.AddPoint(0,    0.00)
        volumeScalarOpacity.AddPoint(500,  0.15)
        volumeScalarOpacity.AddPoint(1000, 0.15)
        volumeScalarOpacity.AddPoint(1150, 0.85)

        volumeGradientOpacity = vtk.vtkPiecewiseFunction()
        volumeGradientOpacity.AddPoint(0,   0.0)
        volumeGradientOpacity.AddPoint(90,  0.5)
        volumeGradientOpacity.AddPoint(100, 1.0)




        volumeColor.AddRGBPoint(0,   0.64, 0.0, 0.0)
        volumeColor.AddRGBPoint(500,  1.0, 1.0, 0.3)
        volumeColor.AddRGBPoint(1000, 1.0, 0.5, 0.3)
        volumeColor.AddRGBPoint(1150, 1.0, 1.0, 0.9)

         




        volumeMapper = vtk.vtkGPUVolumeRayCastMapper()
        volumeMapper.SetInputConnection(reader.GetOutputPort())
        volumeMapper.SetBlendModeToComposite()
        volumeProperty = vtk.vtkVolumeProperty()
        volumeProperty.SetColor(volumeColor)
        volumeProperty.SetScalarOpacity(volumeScalarOpacity)
        volumeProperty.SetGradientOpacity(volumeGradientOpacity)
        volumeProperty.SetInterpolationTypeToLinear()
        volumeProperty.ShadeOn()
        volumeProperty.SetAmbient(0.4)
        volumeProperty.SetDiffuse(0.6)
        volumeProperty.SetSpecular(0.2)

    # The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
    # and orientation of the volume in world coordinates.
        volume = vtk.vtkVolume()
        volume.SetMapper(volumeMapper)
        volume.SetProperty(volumeProperty)

        # Finally, add the volume to the renderer
        ren.AddViewProp(volume)

        # Set up an initial view of the volume.  The focal point will be the
        # center of the volume, and the camera position will be 400mm to the
        # patient's left (which is our right).
        camera =  ren.GetActiveCamera()
        c = volume.GetCenter()
        camera.SetFocalPoint(c[0], c[1], c[2])
        camera.SetPosition(c[0] + 400, c[1], c[2])
        camera.SetViewUp(0, 0, -1)

        # Increase the size of the render window
        self.renWin.SetSize(640, 480)

        # Interact with the data.

        iren.Initialize()
        self.renWin.Render()
        iren.Start()




    


app = QApplication(sys.argv)
# The class that connect Qt with VTK
iren = QVTKRenderWindowInteractor()
w = AppWindow()
w.show()
sys.exit(app.exec_())
# Start the event loop.
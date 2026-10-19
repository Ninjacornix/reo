# SPDX-License-Identifier: GPL-3.0-only
# Original procedural launcher art. No game images, logos, or external assets.
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName PresentationCore, WindowsBase
$assetPath = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../Assets'))
function Brush([string]$color) { return [Windows.Media.BrushConverter]::new().ConvertFromString($color) }
foreach ($edition in @(1,2)) {
    foreach ($poster in @($false,$true)) {
        $width = if ($poster) {320} else {1280}
        $height = if ($poster) {480} else {800}
        $visual = [Windows.Media.DrawingVisual]::new()
        $draw = $visual.RenderOpen()
        $sky = [Windows.Media.LinearGradientBrush]::new()
        $sky.StartPoint = [Windows.Point]::new(0,0); $sky.EndPoint = [Windows.Point]::new(1,1)
        $sky.GradientStops.Add([Windows.Media.GradientStop]::new([Windows.Media.ColorConverter]::ConvertFromString('#101619'),0))
        $tint = if ($edition -eq 1) {'#5B3033'} else {'#294B50'}
        $light = if ($edition -eq 1) {'#C18A77'} else {'#82B2AC'}
        $sky.GradientStops.Add([Windows.Media.GradientStop]::new([Windows.Media.ColorConverter]::ConvertFromString($tint),1))
        $draw.DrawRectangle($sky,$null,[Windows.Rect]::new(0,0,$width,$height))
        $random = [Random]::new(1850 + $edition)
        # Distant city silhouettes, intentionally generic rather than game locations.
        for ($layer=0; $layer -lt 3; $layer++) {
            $x = -20.0
            while ($x -lt $width) {
                $buildingWidth = $random.Next(32,100) * $width / 900
                $buildingHeight = $random.Next(90,300) * $height / 700
                $base = $height * (0.70 + 0.10*$layer)
                $top = $base - $buildingHeight
                $color = @('#293033','#20282B','#171E21')[$layer]
                $draw.DrawRectangle((Brush $color),$null,[Windows.Rect]::new($x,$top,$buildingWidth,$height-$top))
                if ($layer -lt 2) {
                    for ($y=$top+14; $y -lt $base; $y+=24) {
                        for ($wx=$x+8; $wx -lt $x+$buildingWidth-5; $wx+=15) {
                            if ($random.NextDouble() -lt 0.22) {
                                $draw.DrawRectangle((Brush $light),$null,[Windows.Rect]::new($wx,$y,3,5))
                            }
                        }
                    }
                }
                $x += $buildingWidth + $random.Next(3,12)
            }
        }
        # A spare doorway and diagonal light beam supply a common launcher motif.
        $doorWidth = $width * $(if ($poster) {0.27} else {0.09})
        $doorHeight = $height * 0.35
        $doorX = $width * $(if ($poster) {0.53} else {0.74})
        $doorY = $height * 0.48
        $beam = [Windows.Media.StreamGeometry]::new(); $ctx=$beam.Open()
        $ctx.BeginFigure([Windows.Point]::new($doorX,$doorY+$doorHeight),$true,$true)
        $ctx.LineTo([Windows.Point]::new($doorX+$doorWidth,$doorY+$doorHeight),$true,$false)
        $ctx.LineTo([Windows.Point]::new($width*0.92,$height),$true,$false)
        $ctx.LineTo([Windows.Point]::new($width*0.18,$height),$true,$false); $ctx.Close()
        $draw.PushOpacity(0.14); $draw.DrawGeometry((Brush $light),$null,$beam); $draw.Pop()
        $draw.DrawRectangle((Brush '#101719'),[Windows.Media.Pen]::new((Brush $light),2),[Windows.Rect]::new($doorX,$doorY,$doorWidth,$doorHeight))
        $draw.DrawRectangle((Brush $light),$null,[Windows.Rect]::new($doorX+$doorWidth-3,$doorY,3,$doorHeight))
        # Fine rain-like lines are deterministic geometry, with no raster input.
        $draw.PushOpacity(0.09)
        $rainPen=[Windows.Media.Pen]::new((Brush '#C9D3D1'),1)
        for ($i=0; $i -lt 85; $i++) {
            $x=$random.NextDouble()*$width; $y=$random.NextDouble()*$height
            $draw.DrawLine($rainPen,[Windows.Point]::new($x,$y),[Windows.Point]::new($x-6,$y+28))
        }
        $draw.Pop(); $draw.Close()
        $bitmap=[Windows.Media.Imaging.RenderTargetBitmap]::new($width,$height,96,96,[Windows.Media.PixelFormats]::Pbgra32)
        $bitmap.Render($visual)
        $encoder=[Windows.Media.Imaging.PngBitmapEncoder]::new()
        $encoder.Frames.Add([Windows.Media.Imaging.BitmapFrame]::Create($bitmap))
        $kind=if($poster){'poster'}else{'background'}
        $output=[IO.File]::Create((Join-Path $assetPath "edition$edition-$kind.png"))
        $encoder.Save($output); $output.Dispose()
    }
}

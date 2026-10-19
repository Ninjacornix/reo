$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$destination = Join-Path $PSScriptRoot '../launcher/Assets'
$images = foreach ($size in @(16, 24, 32, 48, 64, 128, 256)) {
    $bitmap = [Drawing.Bitmap]::new($size, $size)
    $graphics = [Drawing.Graphics]::FromImage($bitmap)
    $graphics.SmoothingMode = [Drawing.Drawing2D.SmoothingMode]::AntiAlias
    $graphics.ScaleTransform($size / 256.0, $size / 256.0)
    $background = [Drawing.SolidBrush]::new([Drawing.ColorTranslator]::FromHtml('#171b20'))
    $frame = [Drawing.SolidBrush]::new([Drawing.ColorTranslator]::FromHtml('#e9e5da'))
    $door = [Drawing.SolidBrush]::new([Drawing.ColorTranslator]::FromHtml('#ba4449'))
    $outline = [Drawing.Drawing2D.GraphicsPath]::new()
    $outline.AddArc(0, 0, 96, 96, 180, 90)
    $outline.AddArc(160, 0, 96, 96, 270, 90)
    $outline.AddArc(160, 160, 96, 96, 0, 90)
    $outline.AddArc(0, 160, 96, 96, 90, 90)
    $outline.CloseFigure()
    $graphics.FillPath($background, $outline)
    $graphics.FillPolygon($frame, [Drawing.PointF[]]@(
        [Drawing.PointF]::new(64,48), [Drawing.PointF]::new(188,48),
        [Drawing.PointF]::new(188,208), [Drawing.PointF]::new(160,208),
        [Drawing.PointF]::new(160,76), [Drawing.PointF]::new(92,76),
        [Drawing.PointF]::new(92,208), [Drawing.PointF]::new(64,208)))
    $graphics.FillPolygon($door, [Drawing.PointF[]]@(
        [Drawing.PointF]::new(106,90), [Drawing.PointF]::new(150,76),
        [Drawing.PointF]::new(150,208), [Drawing.PointF]::new(106,222)))
    $graphics.FillRectangle($background, 133,145,7,12)
    $stream = [IO.MemoryStream]::new()
    $bitmap.Save($stream, [Drawing.Imaging.ImageFormat]::Png)
    if ($size -eq 256) { [IO.File]::WriteAllBytes((Join-Path $destination 'app-icon.png'), $stream.ToArray()) }
    [pscustomobject]@{ Size = $size; Bytes = $stream.ToArray() }
    $stream.Dispose(); $graphics.Dispose(); $bitmap.Dispose()
    $outline.Dispose(); $background.Dispose(); $frame.Dispose(); $door.Dispose()
}
$output = [IO.MemoryStream]::new()
$writer = [IO.BinaryWriter]::new($output)
$writer.Write([uint16]0); $writer.Write([uint16]1); $writer.Write([uint16]$images.Count)
$offset = 6 + 16 * $images.Count
foreach ($image in $images) {
    $dimension = if ($image.Size -eq 256) { 0 } else { $image.Size }
    $writer.Write([byte]$dimension); $writer.Write([byte]$dimension)
    $writer.Write([uint16]0); $writer.Write([uint16]1); $writer.Write([uint16]32)
    $writer.Write([uint32]$image.Bytes.Length); $writer.Write([uint32]$offset)
    $offset += $image.Bytes.Length
}
foreach ($image in $images) { $writer.Write([byte[]]$image.Bytes) }
[IO.File]::WriteAllBytes((Join-Path $destination 'app-icon.ico'), $output.ToArray())
$writer.Dispose(); $output.Dispose()

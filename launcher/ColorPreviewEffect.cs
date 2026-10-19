using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Effects;

namespace Outbreak.Launcher;

public sealed class ColorPreviewEffect : ShaderEffect {
    public static readonly DependencyProperty InputProperty =
        RegisterPixelShaderSamplerProperty("Input", typeof(ColorPreviewEffect), 0);
    public static readonly DependencyProperty GainProperty =
        DependencyProperty.Register("Gain", typeof(double), typeof(ColorPreviewEffect),
                                    new UIPropertyMetadata(1.0, PixelShaderConstantCallback(0)));
    public static readonly DependencyProperty GammaProperty =
        DependencyProperty.Register("Gamma", typeof(double), typeof(ColorPreviewEffect),
                                    new UIPropertyMetadata(1.0, PixelShaderConstantCallback(1)));
    public Brush Input {
        get => (Brush)GetValue(InputProperty);
        set => SetValue(InputProperty, value);
    }
    public double Gain {
        get => (double)GetValue(GainProperty);
        set => SetValue(GainProperty, value);
    }
    public double Gamma {
        get => (double)GetValue(GammaProperty);
        set => SetValue(GammaProperty, value);
    }
    public ColorPreviewEffect() {
        PixelShader = new PixelShader { UriSource = new Uri(
                                            "/Outbreak.Launcher;component/Shaders/ColorPreview.ps",
                                            UriKind.Relative) };
        UpdateShaderValue(InputProperty);
        UpdateShaderValue(GainProperty);
        UpdateShaderValue(GammaProperty);
    }
}

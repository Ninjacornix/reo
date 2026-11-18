"""Stage raylib endpoint selection and safe device shutdown; never edit upstream."""
import argparse
from pathlib import Path


def instrument(source):
    source = source.replace("\r\n", "\n")
    replacements = (
        ("void InitAudioDevice(void)\n{", '#include "runtime/audio/reo_output_device.h"\nvoid InitAudioDevice(void)\n{'),
        ("config.playback.pDeviceID = NULL;  // NULL for the default playback AUDIO.System.device",
         "ma_device_id reoOutputId;\n    config.playback.pDeviceID = reoAudioOutputDevice(&AUDIO.System.context, &reoOutputId);"),
        ("result = ma_device_init(&AUDIO.System.context, &config, &AUDIO.System.device);",
         "result = reoAudioInitDevice(&AUDIO.System.context, &config, &AUDIO.System.device);"),
        # The device callback uses this lock even when no buffers are tracked.
        # ma_device_uninit joins the pinned Windows worker; retain the lock until then.
        ("        ma_mutex_uninit(&AUDIO.System.lock);\n        ma_device_uninit(&AUDIO.System.device);\n        ma_context_uninit(&AUDIO.System.context);",
         "        ma_device_uninit(&AUDIO.System.device);\n        ma_mutex_uninit(&AUDIO.System.lock);\n        ma_context_uninit(&AUDIO.System.context);"),
    )
    for original, replacement in replacements:
        if source.count(original) != 1:
            raise ValueError("The reviewed raylib audio initialization or shutdown changed; audio transform was not applied")
        source = source.replace(original, replacement)
    return "// REO: altered raylib source, adding per-game audio output selection and safe device shutdown.\n" + source


def prepare(source, target):
    source, target = Path(source), Path(target)
    contents = instrument(source.read_text(encoding="utf-8"))
    target.parent.mkdir(parents=True, exist_ok=True)
    if not target.exists() or target.read_text(encoding="utf-8") != contents:
        target.write_text(contents, encoding="utf-8")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("target", type=Path)
    args = parser.parse_args()
    prepare(args.source, args.target)

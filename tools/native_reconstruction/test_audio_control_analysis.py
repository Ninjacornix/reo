import csv
import io
import tempfile
from pathlib import Path
import unittest
from analyze_audio_control_trace import COLUMNS, read_trace, analyze


def row(t, frames, underruns=0, slot=0, generation=1, late=0, skipped=0):
    return [t, t+100, 1, frames, 0, underruns, slot, generation, 1, 1, 0, 17, 0, late, skipped, 256, 1, 48000]


class Analysis(unittest.TestCase):
    def parse(self, rows, dropped=0, extra=''):
        with tempfile.TemporaryDirectory() as folder:
            path=Path(folder)/'trace.csv'
            stream=io.StringIO();stream.write(f'# dropped={dropped}; owner_joined=1; control_snapshots=1\n')
            writer=csv.writer(stream);writer.writerow(COLUMNS);writer.writerows(rows)
            path.write_text(stream.getvalue()+extra)
            return analyze(read_trace(path))

    def test_short_shortage_is_retained(self):
        result=self.parse([row(1000, 0), row(10_001_000, 480, 13, late=13)])
        self.assertEqual(result['measured_underrun_increase'],13)
        self.assertEqual(result['largest_service_gaps'],[])
        self.assertEqual(result['largest_shortage_windows'][0]['missing_counter_increases'][0]['slot'],0)

    def test_healthy_gap_is_not_audio_shortage(self):
        result=self.parse([row(1000,0),row(200_001_000,9600)])
        self.assertEqual(result['shortage_windows'],0)
        self.assertEqual(len(result['largest_service_gaps']),1)

    def test_replacement_does_not_attribute_old_counters(self):
        result=self.parse([row(1000,0,late=30),row(100_001_000,4800,13,generation=2,late=40)])
        self.assertEqual(result['largest_shortage_windows'][0]['missing_counter_increases'],[])

    def test_streams_do_not_duplicate_aggregate(self):
        result=self.parse([row(1000,0),row(1000,0,slot=1),row(100_001_000,4800,13,late=13),row(100_001_000,4800,13,slot=1,late=13)])
        self.assertEqual(result['snapshots'],2)
        self.assertEqual(result['measured_underrun_increase'],13)
        self.assertEqual(len(result['largest_shortage_windows'][0]['missing_counter_increases']),2)

    def test_counter_reset_is_limited(self):
        result=self.parse([row(1000,4800,13),row(100_001_000,0)])
        self.assertEqual(result['status'],'limited observations')
        self.assertEqual(result['shortage_windows'],0)

    def test_partial_row_and_drops_are_explicit(self):
        result=self.parse([row(1000,0)],dropped=2,extra='123,456\n')
        self.assertEqual(result['dropped_snapshots'],2)
        self.assertEqual(len(result['invalid_rows']),1)
        self.assertEqual(result['status'],'limited observations')

    def test_missing_counter_moves_from_late_to_skipped(self):
        result=self.parse([row(1000,4800,13,late=13),row(100_001_000,9600,13,skipped=13)])
        self.assertEqual(result['measured_underrun_increase'],0)


if __name__=='__main__':unittest.main()

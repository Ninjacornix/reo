"""Microinstruction expectations derived independently from 32x32 arithmetic."""
import unittest
import json
from pathlib import Path
import re
import shutil
import subprocess
from ee_mac_oracle import MicroMachine,encode,implementation_identity,GENERATOR,MACROS,ROOT
from sjuni_oracle import OracleError,UnknownInstruction,MASK64,sext32


class MacTests(unittest.TestCase):
    def machine(self):return MicroMachine(hi=0x1234,lo=0x5678,hi1=0x9ABC,lo1=0xDEF0)

    def test_signed_product_halves_and_optional_destination_both_banks(self):
        vectors=[(-1,1,0xFFFFFFFF,0xFFFFFFFF),(-1,-1,0,1),
                 (-2147483648,-2147483648,0x40000000,0),
                 (-2147483648,2147483647,0xC0000000,0x80000000),
                 (2147483647,2147483647,0x3FFFFFFF,1),
                 (65536,32768,0,0x80000000)]
        for op,bank in ((0,''),(0x1C,'1')):
            for a,b,hi,lo in vectors:
                for rd in (0,3,1,2):
                    m=self.machine();before=m.mac_state();m.regs[1]=sext32(a);m.regs[2]=sext32(b)
                    m.instruction(0,encode(op,0x18,1,2,rd))
                    self.assertEqual(getattr(m,'hi'+bank),sext32(hi))
                    self.assertEqual(getattr(m,'lo'+bank),sext32(lo))
                    self.assertEqual(m.regs[rd],sext32(lo) if rd else 0)
                    other='1' if not bank else ''
                    self.assertEqual(getattr(m,'hi'+other),before['hi'+other])
                    self.assertEqual(getattr(m,'lo'+other),before['lo'+other])

    def test_unsigned_product_still_sign_extends_halves(self):
        for op in (0,0x1C):
            m=self.machine();m.regs[1]=m.regs[2]=MASK64
            m.instruction(0,encode(op,0x19,1,2,3));suffix='1' if op else ''
            self.assertEqual(getattr(m,'hi'+suffix),0xFFFFFFFFFFFFFFFE)
            self.assertEqual(getattr(m,'lo'+suffix),1)
            self.assertEqual(m.regs[3],1)

    def test_add_wrap_carry_and_negative_product(self):
        for fn,suffix in ((0,''),(0x20,'1')):
            m=self.machine();setattr(m,'hi'+suffix,0x7FFFFFFF);setattr(m,'lo'+suffix,MASK64)
            m.regs[1]=m.regs[2]=1;m.instruction(0,encode(0x1C,fn,1,2,3))
            self.assertEqual(getattr(m,'hi'+suffix),0xFFFFFFFF80000000)
            self.assertEqual(getattr(m,'lo'+suffix),0)
            setattr(m,'hi'+suffix,MASK64);setattr(m,'lo'+suffix,MASK64)
            m.instruction(0,encode(0x1C,fn,1,2,3))
            self.assertEqual((getattr(m,'hi'+suffix),getattr(m,'lo'+suffix)),(0,0))
            m.regs[1]=MASK64;m.instruction(0,encode(0x1C,fn,1,2,3))
            self.assertEqual((getattr(m,'hi'+suffix),getattr(m,'lo'+suffix)),(MASK64,MASK64))

    def test_unsigned_add_and_only_low_word_of_each_accumulator_half_used(self):
        for fn,suffix in ((1,''),(0x21,'1')):
            m=self.machine();setattr(m,'hi'+suffix,0xAAAAAAAA00000001);setattr(m,'lo'+suffix,0xBBBBBBBBFFFFFFFF)
            m.regs[1]=MASK64;m.regs[2]=2;m.instruction(0,encode(0x1C,fn,1,2,3))
            self.assertEqual((getattr(m,'hi'+suffix),getattr(m,'lo'+suffix)),(3,0xFFFFFFFFFFFFFFFD))

    def test_bank_moves_preserve_all_lower64_and_zero_destination(self):
        for op,suffix in ((0,''),(0x1C,'1')):
            for write,read,bank in ((0x11,0x10,'hi'),(0x13,0x12,'lo')):
                m=self.machine();m.regs[1]=0x0123456789ABCDEF
                m.instruction(0,encode(op,write,rs=1));m.instruction(0,encode(op,read,rd=3))
                self.assertEqual(m.regs[3],0x0123456789ABCDEF)
                self.assertEqual(getattr(m,bank+suffix),m.regs[3])
                m.instruction(0,encode(op,read,rd=0));self.assertEqual(m.regs[0],0)

    def test_noncanonical_sources_reject_before_any_mutation(self):
        for op,fn in ((0,0x18),(0,0x19),(0x1C,0x18),(0x1C,0x19),(0x1C,0),(0x1C,1),(0x1C,0x20),(0x1C,0x21)):
            for bad in (0x00000000FFFFFFFF,0xFFFFFFFF00000000,0x1234567800000001):
                m=self.machine();m.regs[1]=bad;m.regs[2]=1;before=(m.regs.copy(),m.mac_state(),m.mac_counts.copy())
                with self.assertRaises(OracleError):m.instruction(0,encode(op,fn,1,2,3))
                self.assertEqual((m.regs,m.mac_state(),m.mac_counts),before)

    def test_reserved_encoding_and_unknown_forms_fail_closed(self):
        for word in (encode(0,0x18,1,2,3,sa=1),encode(0,0x10,rs=1,rd=3),
                     encode(0x1C,0x11,rs=1,rd=3),encode(0x1C,0x28)):
            m=self.machine();before=(m.regs.copy(),m.mac_state())
            with self.assertRaises(UnknownInstruction):m.instruction(0,word)
            self.assertEqual((m.regs,m.mac_state()),before)
        with self.assertRaises(OracleError):MicroMachine(hi=-1,lo=0,hi1=0,lo1=0)

    def test_exact_local_recompiler_emissions_against_mac_results(self):
        # Recompiler consistency is separate from the hand-calculated tests above.
        # Extract current pinned authored emission templates, never target text.
        identity=implementation_identity();text=GENERATOR.read_text()
        forms=[(0,0x18,'SPECIAL_MULT'),(0,0x19,'SPECIAL_MULTU'),
               (0x1C,0x18,'MMI_MULT1'),(0x1C,0x19,'MMI_MULTU1'),
               (0x1C,0,'MMI_MADD'),(0x1C,1,'MMI_MADDU'),
               (0x1C,0x20,'MMI_MADD1'),(0x1C,0x21,'MMI_MADDU1')]
        fragments=[]
        for _,_,symbol in forms:
            body=text.split('case '+symbol+':',1)[1].split('case ',1)[0]
            templates=re.findall(r'return fmt::format\("([^"\n]+)", ([^;\n]+)\);',body)
            self.assertEqual(len(templates),2)
            for rd,(template,args) in ((3,templates[0]),(0,templates[1])):
                values={'inst.rs':1,'inst.rt':2,'inst.rd':rd,'rs':1,'rt':2,'rd':rd}
                code=template.format(*(values[arg.strip()] for arg in args.split(',')))
                fragments.append(code)
        macro_text=MACROS.read_text()
        helper='\n'.join(re.search(r'static inline uint64_t '+name+r'\([^}]+\}',macro_text).group(0)
                         for name in ('Ps2HiLoToU64','Ps2SignExt32ToU64'))
        preamble='''#include <cstdint>
#include <iostream>
struct Context { uint64_t r[32]{};uint64_t hi{},lo{},hi1{},lo1{}; };
#define GPR_U32(c,n) static_cast<uint32_t>((c)->r[n])
#define GPR_S32(c,n) static_cast<int32_t>((c)->r[n])
#define SET_GPR_S32(c,n,v) do { if(n) (c)->r[n]=static_cast<uint64_t>(static_cast<int64_t>(static_cast<int32_t>(v))); } while(false)
'''
        switch='void execute(int kind,Context* ctx) { switch(kind) {\n'+''.join(
            f'case {i}: {code} break;\n' for i,code in enumerate(fragments))+'default: break; }}\n'
        expected=[];calls=[]
        for fi,(op,fn,_) in enumerate(forms):
            for rdi,rd in enumerate((3,0)):
                for a,b in ((-1,1),(-1,-1),(-2147483648,-2147483648),(-2147483648,2147483647),(65536,32768),(2147483647,2147483647)):
                    for hi,lo,hi1,lo1 in ((0x7FFFFFFF,MASK64,MASK64,0),(0xAAAAAAAA00000001,0xBBBBBBBBFFFFFFFF,0x123456789ABCDEF0,0xFEDCBA9876543210)):
                        m=MicroMachine(hi=hi,lo=lo,hi1=hi1,lo1=lo1);m.regs[1]=sext32(a);m.regs[2]=sext32(b)
                        m.instruction(0,encode(op,fn,1,2,rd));expected.append([m.hi,m.lo,m.hi1,m.lo1,m.regs[3]])
                        calls.append('{ Context c{};'+''.join(f'c.{field}={value}ull;' for field,value in [('hi',hi),('lo',lo),('hi1',hi1),('lo1',lo1)])+
                            f'c.r[1]={sext32(a)}ull;c.r[2]={sext32(b)}ull;execute({fi*2+rdi},&c);'+
                            'std::cout<<c.hi<<" "<<c.lo<<" "<<c.hi1<<" "<<c.lo1<<" "<<c.r[3]<<"\\n";}\n')
        source=preamble+helper+'\n'+switch+'int main(){\n'+''.join(calls)+'}\n'
        output=ROOT/'build-native-sjuni/ee-mac-emission-check';output.mkdir(parents=True,exist_ok=True)
        cpp=output/'mac_emissions.cpp';exe=output/'mac_emissions.exe';cpp.write_text(source)
        compiler=shutil.which('g++')
        if compiler is None:self.skipTest('Optional exact-emission C++ check requires g++')
        command=[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Wpedantic','-Werror',str(cpp),'-o',str(exe)]
        subprocess.run(command,check=True,capture_output=True,text=True)
        run=subprocess.run([str(exe)],check=True,capture_output=True,text=True)
        actual=[[int(value) for value in line.split()] for line in run.stdout.splitlines()]
        self.assertEqual(actual,expected)
        (output/'receipt.json').write_text(json.dumps(dict(identity=identity,compiler=compiler,
            command=command,cases=len(expected),passed=True,scope='lower64 emission harness, canonical source words; no runtime link'),indent=2)+'\n')


if __name__=='__main__':unittest.main()

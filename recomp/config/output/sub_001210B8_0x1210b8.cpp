#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001210B8
// Address: 0x1210b8 - 0x121920
void sub_001210B8_0x1210b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001210B8_0x1210b8");
#endif

    switch (ctx->pc) {
        case 0x121150u: goto label_121150;
        case 0x121190u: goto label_121190;
        case 0x1211b0u: goto label_1211b0;
        case 0x1211ecu: goto label_1211ec;
        case 0x121220u: goto label_121220;
        case 0x121268u: goto label_121268;
        case 0x121280u: goto label_121280;
        case 0x121330u: goto label_121330;
        case 0x1213d4u: goto label_1213d4;
        case 0x121400u: goto label_121400;
        case 0x121448u: goto label_121448;
        case 0x1214b0u: goto label_1214b0;
        case 0x1214d8u: goto label_1214d8;
        case 0x121550u: goto label_121550;
        case 0x121580u: goto label_121580;
        case 0x121600u: goto label_121600;
        case 0x121620u: goto label_121620;
        case 0x121668u: goto label_121668;
        case 0x121690u: goto label_121690;
        case 0x121738u: goto label_121738;
        case 0x121780u: goto label_121780;
        case 0x1217c0u: goto label_1217c0;
        case 0x121808u: goto label_121808;
        case 0x121850u: goto label_121850;
        case 0x121898u: goto label_121898;
        default: break;
    }

    ctx->pc = 0x1210b8u;

    // 0x1210b8: 0x24c2fffd  addiu       $v0, $a2, -0x3
    ctx->pc = 0x1210b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967293));
    // 0x1210bc: 0x24ca0004  addiu       $t2, $a2, 0x4
    ctx->pc = 0x1210bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1210c0: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1210c0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1210c4: 0x27bdfe50  addiu       $sp, $sp, -0x1B0
    ctx->pc = 0x1210c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1210c8: 0x143100b  movn        $v0, $t2, $v1
    ctx->pc = 0x1210c8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 10));
    // 0x1210cc: 0xffb70188  sd          $s7, 0x188($sp)
    ctx->pc = 0x1210ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 392), GPR_U64(ctx, 23));
    // 0x1210d0: 0x2b8c3  sra         $s7, $v0, 3
    ctx->pc = 0x1210d0u;
    SET_GPR_S32(ctx, 23, SRA32(GPR_S32(ctx, 2), 3));
    // 0x1210d4: 0xafa80144  sw          $t0, 0x144($sp)
    ctx->pc = 0x1210d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 324), GPR_U32(ctx, 8));
    // 0x1210d8: 0x2ae20000  slti        $v0, $s7, 0x0
    ctx->pc = 0x1210d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 23) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1210dc: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x1210dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1210e0: 0x2b80b  movn        $s7, $zero, $v0
    ctx->pc = 0x1210e0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 23, GPR_VEC(ctx, 0));
    // 0x1210e4: 0xffb40170  sd          $s4, 0x170($sp)
    ctx->pc = 0x1210e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 368), GPR_U64(ctx, 20));
    // 0x1210e8: 0x3c140024  lui         $s4, 0x24
    ctx->pc = 0x1210e8u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)36 << 16));
    // 0x1210ec: 0x288a021  addu        $s4, $s4, $t0
    ctx->pc = 0x1210ecu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 8)));
    // 0x1210f0: 0x8e9491a8  lw          $s4, -0x6E58($s4)
    ctx->pc = 0x1210f0u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294939048)));
    // 0x1210f4: 0x1710c0  sll         $v0, $s7, 3
    ctx->pc = 0x1210f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 3));
    // 0x1210f8: 0xffb20160  sd          $s2, 0x160($sp)
    ctx->pc = 0x1210f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 352), GPR_U64(ctx, 18));
    // 0x1210fc: 0x24f2ffff  addiu       $s2, $a3, -0x1
    ctx->pc = 0x1210fcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x121100: 0xc23023  subu        $a2, $a2, $v0
    ctx->pc = 0x121100u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x121104: 0x2541821  addu        $v1, $s2, $s4
    ctx->pc = 0x121104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
    // 0x121108: 0xffb10158  sd          $s1, 0x158($sp)
    ctx->pc = 0x121108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 344), GPR_U64(ctx, 17));
    // 0x12110c: 0x24d1fff8  addiu       $s1, $a2, -0x8
    ctx->pc = 0x12110cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967288));
    // 0x121110: 0xffbe0190  sd          $fp, 0x190($sp)
    ctx->pc = 0x121110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 400), GPR_U64(ctx, 30));
    // 0x121114: 0xa0f02d  daddu       $fp, $a1, $zero
    ctx->pc = 0x121114u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121118: 0xffb00150  sd          $s0, 0x150($sp)
    ctx->pc = 0x121118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 336), GPR_U64(ctx, 16));
    // 0x12111c: 0x2f22823  subu        $a1, $s7, $s2
    ctx->pc = 0x12111cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 23), GPR_U32(ctx, 18)));
    // 0x121120: 0xffb30168  sd          $s3, 0x168($sp)
    ctx->pc = 0x121120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 360), GPR_U64(ctx, 19));
    // 0x121124: 0xffb50178  sd          $s5, 0x178($sp)
    ctx->pc = 0x121124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 376), GPR_U64(ctx, 21));
    // 0x121128: 0xffb60180  sd          $s6, 0x180($sp)
    ctx->pc = 0x121128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 384), GPR_U64(ctx, 22));
    // 0x12112c: 0xffbf0198  sd          $ra, 0x198($sp)
    ctx->pc = 0x12112cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 408), GPR_U64(ctx, 31));
    // 0x121130: 0xe7b401a0  swc1        $f20, 0x1A0($sp)
    ctx->pc = 0x121130u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 416), bits); }
    // 0x121134: 0xafa40140  sw          $a0, 0x140($sp)
    ctx->pc = 0x121134u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 320), GPR_U32(ctx, 4));
    // 0x121138: 0x460000f  bltz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x121138u;
    {
        const bool branch_taken_0x121138 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x12113Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121138u;
            // 0x12113c: 0xafa90148  sw          $t1, 0x148($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 328), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121138) {
            ctx->pc = 0x121178u;
            goto label_121178;
        }
    }
    ctx->pc = 0x121140u;
    // 0x121140: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x121140u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x121144: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x121144u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x121148: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x121148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x12114c: 0x27a30050  addiu       $v1, $sp, 0x50
    ctx->pc = 0x12114cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
label_121150:
    // 0x121150: 0x4a20004  bltzl       $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x121150u;
    {
        const bool branch_taken_0x121150 = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x121150) {
            ctx->pc = 0x121154u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121150u;
            // 0x121154: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x121164u;
            goto label_121164;
        }
    }
    ctx->pc = 0x121158u;
    // 0x121158: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x121158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x12115c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x12115cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x121160: 0xe4600000  swc1        $f0, 0x0($v1)
    ctx->pc = 0x121160u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
label_121164:
    // 0x121164: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121164u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121168: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x121168u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x12116c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x12116cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x121170: 0x14c0fff7  bnez        $a2, . + 4 + (-0x9 << 2)
    ctx->pc = 0x121170u;
    {
        const bool branch_taken_0x121170 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x121174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121170u;
            // 0x121174: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121170) {
            ctx->pc = 0x121150u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121150;
        }
    }
    ctx->pc = 0x121178u;
label_121178:
    // 0x121178: 0x680001b  bltz        $s4, . + 4 + (0x1B << 2)
    ctx->pc = 0x121178u;
    {
        const bool branch_taken_0x121178 = (GPR_S64(ctx, 20) < 0);
        ctx->pc = 0x12117Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121178u;
            // 0x12117c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121178) {
            ctx->pc = 0x1211E8u;
            goto label_1211e8;
        }
    }
    ctx->pc = 0x121180u;
    // 0x121180: 0x27a200f0  addiu       $v0, $sp, 0xF0
    ctx->pc = 0x121180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x121184: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x121184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121188: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x121188u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12118c: 0x0  nop
    ctx->pc = 0x12118cu;
    // NOP
label_121190:
    // 0x121190: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x121190u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x121194: 0x642000f  bltzl       $s2, . + 4 + (0xF << 2)
    ctx->pc = 0x121194u;
    {
        const bool branch_taken_0x121194 = (GPR_S64(ctx, 18) < 0);
        if (branch_taken_0x121194) {
            ctx->pc = 0x121198u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121194u;
            // 0x121198: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1211D4u;
            goto label_1211d4;
        }
    }
    ctx->pc = 0x12119Cu;
    // 0x12119c: 0x27a50050  addiu       $a1, $sp, 0x50
    ctx->pc = 0x12119cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1211a0: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1211a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1211a4: 0x8fa30140  lw          $v1, 0x140($sp)
    ctx->pc = 0x1211a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1211a8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1211a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1211ac: 0x26450001  addiu       $a1, $s2, 0x1
    ctx->pc = 0x1211acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1211b0:
    // 0x1211b0: 0xc4600000  lwc1        $f0, 0x0($v1)
    ctx->pc = 0x1211b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1211b4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1211b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1211b8: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1211b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1211bc: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x1211bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x1211c0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1211c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1211c4: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1211c4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1211c8: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1211C8u;
    {
        const bool branch_taken_0x1211c8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1211CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1211C8u;
            // 0x1211cc: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1211c8) {
            ctx->pc = 0x1211B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1211b0;
        }
    }
    ctx->pc = 0x1211D0u;
    // 0x1211d0: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1211d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1211d4:
    // 0x1211d4: 0xe4e20000  swc1        $f2, 0x0($a3)
    ctx->pc = 0x1211d4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 0), bits); }
    // 0x1211d8: 0x286102a  slt         $v0, $s4, $a2
    ctx->pc = 0x1211d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1211dc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1211dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1211e0: 0x1040ffeb  beqz        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1211E0u;
    {
        const bool branch_taken_0x1211e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1211E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1211E0u;
            // 0x1211e4: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1211e0) {
            ctx->pc = 0x121190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121190;
        }
    }
    ctx->pc = 0x1211E8u;
label_1211e8:
    // 0x1211e8: 0x280802d  daddu       $s0, $s4, $zero
    ctx->pc = 0x1211e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1211ec:
    // 0x1211ec: 0x109880  sll         $s3, $s0, 2
    ctx->pc = 0x1211ecu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1211f0: 0x27a300f0  addiu       $v1, $sp, 0xF0
    ctx->pc = 0x1211f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1211f4: 0x731021  addu        $v0, $v1, $s3
    ctx->pc = 0x1211f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x1211f8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1211f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1211fc: 0x1a000017  blez        $s0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1211FCu;
    {
        const bool branch_taken_0x1211fc = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x121200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1211FCu;
            // 0x121200: 0xc4540000  lwc1        $f20, 0x0($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1211fc) {
            ctx->pc = 0x12125Cu;
            goto label_12125c;
        }
    }
    ctx->pc = 0x121204u;
    // 0x121204: 0x3c013b80  lui         $at, 0x3B80
    ctx->pc = 0x121204u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15232 << 16));
    // 0x121208: 0x44812000  mtc1        $at, $f4
    ctx->pc = 0x121208u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x12120c: 0x2443fffc  addiu       $v1, $v0, -0x4
    ctx->pc = 0x12120cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x121210: 0x3c014380  lui         $at, 0x4380
    ctx->pc = 0x121210u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17280 << 16));
    // 0x121214: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x121214u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x121218: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x121218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12121c: 0x0  nop
    ctx->pc = 0x12121cu;
    // NOP
label_121220:
    // 0x121220: 0x4604a002  mul.s       $f0, $f20, $f4
    ctx->pc = 0x121220u;
    ctx->f[0] = FPU_MUL_S(ctx->f[20], ctx->f[4]);
    // 0x121224: 0xc4610000  lwc1        $f1, 0x0($v1)
    ctx->pc = 0x121224u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x121228: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x121228u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x12122c: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x12122cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x121230: 0x460000a4  .word       0x460000A4                   # cvt.w.s     $f2, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x121230u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x121234: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x121234u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x121238: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x121238u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x12123c: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x12123cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x121240: 0x46031002  mul.s       $f0, $f2, $f3
    ctx->pc = 0x121240u;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x121244: 0x4600a001  sub.s       $f0, $f20, $f0
    ctx->pc = 0x121244u;
    ctx->f[0] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
    // 0x121248: 0x46020d00  add.s       $f20, $f1, $f2
    ctx->pc = 0x121248u;
    ctx->f[20] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x12124c: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x12124cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x121250: 0xe4810000  swc1        $f1, 0x0($a0)
    ctx->pc = 0x121250u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x121254: 0x1ca0fff2  bgtz        $a1, . + 4 + (-0xE << 2)
    ctx->pc = 0x121254u;
    {
        const bool branch_taken_0x121254 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x121258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121254u;
            // 0x121258: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121254) {
            ctx->pc = 0x121220u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121220;
        }
    }
    ctx->pc = 0x12125Cu;
label_12125c:
    // 0x12125c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x12125cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x121260: 0xc0428e0  jal         func_10A380
    ctx->pc = 0x121260u;
    SET_GPR_U32(ctx, 31, 0x121268u);
    ctx->pc = 0x121264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121260u;
            // 0x121264: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A380u;
    if (runtime->hasFunction(0x10A380u)) {
        auto targetFn = runtime->lookupFunction(0x10A380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121268u; }
        if (ctx->pc != 0x121268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A380_0x10a380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121268u; }
        if (ctx->pc != 0x121268u) { return; }
    }
    ctx->pc = 0x121268u;
label_121268:
    // 0x121268: 0x3c013e00  lui         $at, 0x3E00
    ctx->pc = 0x121268u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15872 << 16));
    // 0x12126c: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x12126cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x121270: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x121270u;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
    // 0x121274: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x121274u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121278: 0xc048934  jal         func_1224D0
    ctx->pc = 0x121278u;
    SET_GPR_U32(ctx, 31, 0x121280u);
    ctx->pc = 0x12127Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121278u;
            // 0x12127c: 0x460ca302  mul.s       $f12, $f20, $f12 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[20], ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1224D0u;
    if (runtime->hasFunction(0x1224D0u)) {
        auto targetFn = runtime->lookupFunction(0x1224D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121280u; }
        if (ctx->pc != 0x121280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001224D0_0x1224d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121280u; }
        if (ctx->pc != 0x121280u) { return; }
    }
    ctx->pc = 0x121280u;
label_121280:
    // 0x121280: 0x3c014100  lui         $at, 0x4100
    ctx->pc = 0x121280u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16640 << 16));
    // 0x121284: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x121284u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121288: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x121288u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x12128c: 0x4600a501  sub.s       $f20, $f20, $f0
    ctx->pc = 0x12128cu;
    ctx->f[20] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
    // 0x121290: 0x4600a024  .word       0x4600A024                   # cvt.w.s     $f0, $f20 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x121290u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[20]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x121294: 0x44150000  mfc1        $s5, $f0
    ctx->pc = 0x121294u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x121298: 0x44950000  mtc1        $s5, $f0
    ctx->pc = 0x121298u;
    { uint32_t bits = GPR_U32(ctx, 21); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x12129c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x12129cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1212a0: 0x1a20000f  blez        $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x1212A0u;
    {
        const bool branch_taken_0x1212a0 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x1212A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1212A0u;
            // 0x1212a4: 0x4600a501  sub.s       $f20, $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1212a0) {
            ctx->pc = 0x1212E0u;
            goto label_1212e0;
        }
    }
    ctx->pc = 0x1212A8u;
    // 0x1212a8: 0x2663fffc  addiu       $v1, $s3, -0x4
    ctx->pc = 0x1212a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x1212ac: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1212acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1212b0: 0x3a32821  addu        $a1, $sp, $v1
    ctx->pc = 0x1212b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 3)));
    // 0x1212b4: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x1212b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1212b8: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1212b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1212bc: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x1212bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1212c0: 0x912023  subu        $a0, $a0, $s1
    ctx->pc = 0x1212c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1212c4: 0x433007  srav        $a2, $v1, $v0
    ctx->pc = 0x1212c4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1212c8: 0x461004  sllv        $v0, $a2, $v0
    ctx->pc = 0x1212c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x1212cc: 0x2a6a821  addu        $s5, $s5, $a2
    ctx->pc = 0x1212ccu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 6)));
    // 0x1212d0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1212d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1212d4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1212d4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1212d8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1212D8u;
    {
        const bool branch_taken_0x1212d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1212DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1212D8u;
            // 0x1212dc: 0x83b007  srav        $s6, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1212d8) {
            ctx->pc = 0x12130Cu;
            goto label_12130c;
        }
    }
    ctx->pc = 0x1212E0u;
label_1212e0:
    // 0x1212e0: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1212E0u;
    {
        const bool branch_taken_0x1212e0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1212E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1212E0u;
            // 0x1212e4: 0x27d1021  addu        $v0, $s3, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1212e0) {
            ctx->pc = 0x1212F8u;
            goto label_1212f8;
        }
    }
    ctx->pc = 0x1212E8u;
    // 0x1212e8: 0x8c43fffc  lw          $v1, -0x4($v0)
    ctx->pc = 0x1212e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294967292)));
    // 0x1212ec: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1212ECu;
    {
        const bool branch_taken_0x1212ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1212F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1212ECu;
            // 0x1212f0: 0x3b203  sra         $s6, $v1, 8 (Delay Slot)
        SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 3), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1212ec) {
            ctx->pc = 0x12130Cu;
            goto label_12130c;
        }
    }
    ctx->pc = 0x1212F4u;
    // 0x1212f4: 0x0  nop
    ctx->pc = 0x1212f4u;
    // NOP
label_1212f8:
    // 0x1212f8: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x1212f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x1212fc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1212fcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x121300: 0x46140036  c.le.s      $f0, $f20
    ctx->pc = 0x121300u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x121304: 0x45030001  bc1tl       . + 4 + (0x1 << 2)
    ctx->pc = 0x121304u;
    {
        const bool branch_taken_0x121304 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x121304) {
            ctx->pc = 0x121308u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121304u;
            // 0x121308: 0x24160002  addiu       $s6, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12130Cu;
            goto label_12130c;
        }
    }
    ctx->pc = 0x12130Cu;
label_12130c:
    // 0x12130c: 0x1ac00032  blez        $s6, . + 4 + (0x32 << 2)
    ctx->pc = 0x12130Cu;
    {
        const bool branch_taken_0x12130c = (GPR_S64(ctx, 22) <= 0);
        if (branch_taken_0x12130c) {
            ctx->pc = 0x1213D8u;
            goto label_1213d8;
        }
    }
    ctx->pc = 0x121314u;
    // 0x121314: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x121314u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x121318: 0x1a000012  blez        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x121318u;
    {
        const bool branch_taken_0x121318 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12131Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121318u;
            // 0x12131c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121318) {
            ctx->pc = 0x121364u;
            goto label_121364;
        }
    }
    ctx->pc = 0x121320u;
    // 0x121320: 0x24080100  addiu       $t0, $zero, 0x100
    ctx->pc = 0x121320u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x121324: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x121324u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x121328: 0x3a0182d  daddu       $v1, $sp, $zero
    ctx->pc = 0x121328u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12132c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12132cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_121330:
    // 0x121330: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x121330u;
    {
        const bool branch_taken_0x121330 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x121334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121330u;
            // 0x121334: 0x8c650000  lw          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121330) {
            ctx->pc = 0x121348u;
            goto label_121348;
        }
    }
    ctx->pc = 0x121338u;
    // 0x121338: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x121338u;
    {
        const bool branch_taken_0x121338 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x12133Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121338u;
            // 0x12133c: 0x1051023  subu        $v0, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121338) {
            ctx->pc = 0x121350u;
            goto label_121350;
        }
    }
    ctx->pc = 0x121340u;
    // 0x121340: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x121340u;
    {
        const bool branch_taken_0x121340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121340u;
            // 0x121344: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121340) {
            ctx->pc = 0x12134Cu;
            goto label_12134c;
        }
    }
    ctx->pc = 0x121348u;
label_121348:
    // 0x121348: 0x851023  subu        $v0, $a0, $a1
    ctx->pc = 0x121348u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
label_12134c:
    // 0x12134c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12134cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_121350:
    // 0x121350: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121350u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121354: 0x0  nop
    ctx->pc = 0x121354u;
    // NOP
    // 0x121358: 0x0  nop
    ctx->pc = 0x121358u;
    // NOP
    // 0x12135c: 0x14c0fff4  bnez        $a2, . + 4 + (-0xC << 2)
    ctx->pc = 0x12135Cu;
    {
        const bool branch_taken_0x12135c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x121360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12135Cu;
            // 0x121360: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12135c) {
            ctx->pc = 0x121330u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121330;
        }
    }
    ctx->pc = 0x121364u;
label_121364:
    // 0x121364: 0x1a200013  blez        $s1, . + 4 + (0x13 << 2)
    ctx->pc = 0x121364u;
    {
        const bool branch_taken_0x121364 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x121368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121364u;
            // 0x121368: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121364) {
            ctx->pc = 0x1213B4u;
            goto label_1213b4;
        }
    }
    ctx->pc = 0x12136Cu;
    // 0x12136c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12136cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x121370: 0x12220005  beq         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x121370u;
    {
        const bool branch_taken_0x121370 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x121374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121370u;
            // 0x121374: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121370) {
            ctx->pc = 0x121388u;
            goto label_121388;
        }
    }
    ctx->pc = 0x121378u;
    // 0x121378: 0x52220009  beql        $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x121378u;
    {
        const bool branch_taken_0x121378 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x121378) {
            ctx->pc = 0x12137Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121378u;
            // 0x12137c: 0x2662fffc  addiu       $v0, $s3, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1213A0u;
            goto label_1213a0;
        }
    }
    ctx->pc = 0x121380u;
    // 0x121380: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x121380u;
    {
        const bool branch_taken_0x121380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x121380) {
            ctx->pc = 0x1213B4u;
            goto label_1213b4;
        }
    }
    ctx->pc = 0x121388u;
label_121388:
    // 0x121388: 0x2662fffc  addiu       $v0, $s3, -0x4
    ctx->pc = 0x121388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x12138c: 0x3a22021  addu        $a0, $sp, $v0
    ctx->pc = 0x12138cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x121390: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x121390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x121394: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x121394u;
    {
        const bool branch_taken_0x121394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121394u;
            // 0x121398: 0x3063007f  andi        $v1, $v1, 0x7F (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
        ctx->in_delay_slot = false;
        if (branch_taken_0x121394) {
            ctx->pc = 0x1213ACu;
            goto label_1213ac;
        }
    }
    ctx->pc = 0x12139Cu;
    // 0x12139c: 0x0  nop
    ctx->pc = 0x12139cu;
    // NOP
label_1213a0:
    // 0x1213a0: 0x3a22021  addu        $a0, $sp, $v0
    ctx->pc = 0x1213a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x1213a4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1213a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1213a8: 0x3063003f  andi        $v1, $v1, 0x3F
    ctx->pc = 0x1213a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)63);
label_1213ac:
    // 0x1213ac: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x1213acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x1213b0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1213b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1213b4:
    // 0x1213b4: 0x16c20008  bne         $s6, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1213B4u;
    {
        const bool branch_taken_0x1213b4 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 2));
        if (branch_taken_0x1213b4) {
            ctx->pc = 0x1213D8u;
            goto label_1213d8;
        }
    }
    ctx->pc = 0x1213BCu;
    // 0x1213bc: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1213bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1213c0: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x1213c0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x1213c4: 0x10e00004  beqz        $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x1213C4u;
    {
        const bool branch_taken_0x1213c4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1213C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1213C4u;
            // 0x1213c8: 0x46146501  sub.s       $f20, $f12, $f20 (Delay Slot)
        ctx->f[20] = FPU_SUB_S(ctx->f[12], ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1213c4) {
            ctx->pc = 0x1213D8u;
            goto label_1213d8;
        }
    }
    ctx->pc = 0x1213CCu;
    // 0x1213cc: 0xc0428e0  jal         func_10A380
    ctx->pc = 0x1213CCu;
    SET_GPR_U32(ctx, 31, 0x1213D4u);
    ctx->pc = 0x1213D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1213CCu;
            // 0x1213d0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A380u;
    if (runtime->hasFunction(0x10A380u)) {
        auto targetFn = runtime->lookupFunction(0x10A380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1213D4u; }
        if (ctx->pc != 0x1213D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A380_0x10a380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1213D4u; }
        if (ctx->pc != 0x1213D4u) { return; }
    }
    ctx->pc = 0x1213D4u;
label_1213d4:
    // 0x1213d4: 0x4600a501  sub.s       $f20, $f20, $f0
    ctx->pc = 0x1213d4u;
    ctx->f[20] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
label_1213d8:
    // 0x1213d8: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1213d8u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1213dc: 0x4600a032  c.eq.s      $f20, $f0
    ctx->pc = 0x1213dcu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1213e0: 0x45000051  bc1f        . + 4 + (0x51 << 2)
    ctx->pc = 0x1213E0u;
    {
        const bool branch_taken_0x1213e0 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1213E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1213E0u;
            // 0x1213e4: 0x2606ffff  addiu       $a2, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1213e0) {
            ctx->pc = 0x121528u;
            goto label_121528;
        }
    }
    ctx->pc = 0x1213E8u;
    // 0x1213e8: 0xd4102a  slt         $v0, $a2, $s4
    ctx->pc = 0x1213e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1213ec: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1213ECu;
    {
        const bool branch_taken_0x1213ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1213F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1213ECu;
            // 0x1213f0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1213ec) {
            ctx->pc = 0x12141Cu;
            goto label_12141c;
        }
    }
    ctx->pc = 0x1213F4u;
    // 0x1213f4: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x1213f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1213f8: 0x5d2021  addu        $a0, $v0, $sp
    ctx->pc = 0x1213f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1213fc: 0x0  nop
    ctx->pc = 0x1213fcu;
    // NOP
label_121400:
    // 0x121400: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x121400u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x121404: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x121404u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x121408: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121408u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x12140c: 0xd4102a  slt         $v0, $a2, $s4
    ctx->pc = 0x12140cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x121410: 0x0  nop
    ctx->pc = 0x121410u;
    // NOP
    // 0x121414: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x121414u;
    {
        const bool branch_taken_0x121414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121414u;
            // 0x121418: 0xa32825  or          $a1, $a1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121414) {
            ctx->pc = 0x121400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121400;
        }
    }
    ctx->pc = 0x12141Cu;
label_12141c:
    // 0x12141c: 0x14a00040  bnez        $a1, . + 4 + (0x40 << 2)
    ctx->pc = 0x12141Cu;
    {
        const bool branch_taken_0x12141c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x121420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12141Cu;
            // 0x121420: 0x2682ffff  addiu       $v0, $s4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12141c) {
            ctx->pc = 0x121520u;
            goto label_121520;
        }
    }
    ctx->pc = 0x121424u;
    // 0x121424: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x121424u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x121428: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x121428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x12142c: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x12142cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x121430: 0x1480000c  bnez        $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x121430u;
    {
        const bool branch_taken_0x121430 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x121434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121430u;
            // 0x121434: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121430) {
            ctx->pc = 0x121464u;
            goto label_121464;
        }
    }
    ctx->pc = 0x121438u;
    // 0x121438: 0x141080  sll         $v0, $s4, 2
    ctx->pc = 0x121438u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x12143c: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x12143cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x121440: 0x2443fffc  addiu       $v1, $v0, -0x4
    ctx->pc = 0x121440u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x121444: 0x0  nop
    ctx->pc = 0x121444u;
    // NOP
label_121448:
    // 0x121448: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x121448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x12144c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12144cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x121450: 0x0  nop
    ctx->pc = 0x121450u;
    // NOP
    // 0x121454: 0x0  nop
    ctx->pc = 0x121454u;
    // NOP
    // 0x121458: 0x0  nop
    ctx->pc = 0x121458u;
    // NOP
    // 0x12145c: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12145Cu;
    {
        const bool branch_taken_0x12145c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12145Cu;
            // 0x121460: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12145c) {
            ctx->pc = 0x121448u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121448;
        }
    }
    ctx->pc = 0x121464u;
label_121464:
    // 0x121464: 0x2084821  addu        $t1, $s0, $t0
    ctx->pc = 0x121464u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x121468: 0x26060001  addiu       $a2, $s0, 0x1
    ctx->pc = 0x121468u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x12146c: 0x126102a  slt         $v0, $t1, $a2
    ctx->pc = 0x12146cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x121470: 0x1440ff5e  bnez        $v0, . + 4 + (-0xA2 << 2)
    ctx->pc = 0x121470u;
    {
        const bool branch_taken_0x121470 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x121474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121470u;
            // 0x121474: 0x120802d  daddu       $s0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121470) {
            ctx->pc = 0x1211ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1211ec;
        }
    }
    ctx->pc = 0x121478u;
    // 0x121478: 0x8fab0148  lw          $t3, 0x148($sp)
    ctx->pc = 0x121478u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 328)));
    // 0x12147c: 0x2461021  addu        $v0, $s2, $a2
    ctx->pc = 0x12147cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 6)));
    // 0x121480: 0x2e62021  addu        $a0, $s7, $a2
    ctx->pc = 0x121480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 6)));
    // 0x121484: 0x27a50050  addiu       $a1, $sp, 0x50
    ctx->pc = 0x121484u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x121488: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x121488u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x12148c: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x12148cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x121490: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x121490u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121494: 0x27a700f0  addiu       $a3, $sp, 0xF0
    ctx->pc = 0x121494u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x121498: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x121498u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x12149c: 0xa0582d  daddu       $t3, $a1, $zero
    ctx->pc = 0x12149cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1214a0: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1214a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1214a4: 0x454021  addu        $t0, $v0, $a1
    ctx->pc = 0x1214a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1214a8: 0x120502d  daddu       $t2, $t1, $zero
    ctx->pc = 0x1214a8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1214ac: 0x0  nop
    ctx->pc = 0x1214acu;
    // NOP
label_1214b0:
    // 0x1214b0: 0xc4800000  lwc1        $f0, 0x0($a0)
    ctx->pc = 0x1214b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1214b4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1214b4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1214b8: 0x2461021  addu        $v0, $s2, $a2
    ctx->pc = 0x1214b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 6)));
    // 0x1214bc: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x1214bcu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1214c0: 0x640000d  bltz        $s2, . + 4 + (0xD << 2)
    ctx->pc = 0x1214C0u;
    {
        const bool branch_taken_0x1214c0 = (GPR_S64(ctx, 18) < 0);
        ctx->pc = 0x1214C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1214C0u;
            // 0x1214c4: 0xe5000000  swc1        $f0, 0x0($t0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1214c0) {
            ctx->pc = 0x1214F8u;
            goto label_1214f8;
        }
    }
    ctx->pc = 0x1214C8u;
    // 0x1214c8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1214c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1214cc: 0x8fa70140  lw          $a3, 0x140($sp)
    ctx->pc = 0x1214ccu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1214d0: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x1214d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1214d4: 0x26450001  addiu       $a1, $s2, 0x1
    ctx->pc = 0x1214d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1214d8:
    // 0x1214d8: 0xc4e00000  lwc1        $f0, 0x0($a3)
    ctx->pc = 0x1214d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1214dc: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1214dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1214e0: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1214e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1214e4: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x1214e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x1214e8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1214e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1214ec: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1214ecu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1214f0: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1214F0u;
    {
        const bool branch_taken_0x1214f0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1214F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1214F0u;
            // 0x1214f4: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1214f0) {
            ctx->pc = 0x1214D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1214d8;
        }
    }
    ctx->pc = 0x1214F8u;
label_1214f8:
    // 0x1214f8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1214f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1214fc: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x1214fcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x121500: 0x146102a  slt         $v0, $t2, $a2
    ctx->pc = 0x121500u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x121504: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x121504u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x121508: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x121508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x12150c: 0x1040ffe8  beqz        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x12150Cu;
    {
        const bool branch_taken_0x12150c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12150Cu;
            // 0x121510: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12150c) {
            ctx->pc = 0x1214B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1214b0;
        }
    }
    ctx->pc = 0x121514u;
    // 0x121514: 0x1000ff35  b           . + 4 + (-0xCB << 2)
    ctx->pc = 0x121514u;
    {
        const bool branch_taken_0x121514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121514u;
            // 0x121518: 0x120802d  daddu       $s0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121514) {
            ctx->pc = 0x1211ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1211ec;
        }
    }
    ctx->pc = 0x12151Cu;
    // 0x12151c: 0x0  nop
    ctx->pc = 0x12151cu;
    // NOP
label_121520:
    // 0x121520: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x121520u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x121524: 0x4600a032  c.eq.s      $f20, $f0
    ctx->pc = 0x121524u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
label_121528:
    // 0x121528: 0x45000013  bc1f        . + 4 + (0x13 << 2)
    ctx->pc = 0x121528u;
    {
        const bool branch_taken_0x121528 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x12152Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121528u;
            // 0x12152c: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x121528) {
            ctx->pc = 0x121578u;
            goto label_121578;
        }
    }
    ctx->pc = 0x121530u;
    // 0x121530: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x121530u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x121534: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x121534u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x121538: 0x3a21021  addu        $v0, $sp, $v0
    ctx->pc = 0x121538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x12153c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12153cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x121540: 0x1460002b  bnez        $v1, . + 4 + (0x2B << 2)
    ctx->pc = 0x121540u;
    {
        const bool branch_taken_0x121540 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x121544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121540u;
            // 0x121544: 0x2631fff8  addiu       $s1, $s1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121540) {
            ctx->pc = 0x1215F0u;
            goto label_1215f0;
        }
    }
    ctx->pc = 0x121548u;
    // 0x121548: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x121548u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12154c: 0x0  nop
    ctx->pc = 0x12154cu;
    // NOP
label_121550:
    // 0x121550: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x121550u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x121554: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x121554u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x121558: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x121558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12155c: 0x0  nop
    ctx->pc = 0x12155cu;
    // NOP
    // 0x121560: 0x0  nop
    ctx->pc = 0x121560u;
    // NOP
    // 0x121564: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x121564u;
    {
        const bool branch_taken_0x121564 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121564u;
            // 0x121568: 0x2631fff8  addiu       $s1, $s1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121564) {
            ctx->pc = 0x121550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121550;
        }
    }
    ctx->pc = 0x12156Cu;
    // 0x12156c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x12156Cu;
    {
        const bool branch_taken_0x12156c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12156c) {
            ctx->pc = 0x1215F0u;
            goto label_1215f0;
        }
    }
    ctx->pc = 0x121574u;
    // 0x121574: 0x0  nop
    ctx->pc = 0x121574u;
    // NOP
label_121578:
    // 0x121578: 0xc0428e0  jal         func_10A380
    ctx->pc = 0x121578u;
    SET_GPR_U32(ctx, 31, 0x121580u);
    ctx->pc = 0x12157Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121578u;
            // 0x12157c: 0x112023  negu        $a0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A380u;
    if (runtime->hasFunction(0x10A380u)) {
        auto targetFn = runtime->lookupFunction(0x10A380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121580u; }
        if (ctx->pc != 0x121580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A380_0x10a380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121580u; }
        if (ctx->pc != 0x121580u) { return; }
    }
    ctx->pc = 0x121580u;
label_121580:
    // 0x121580: 0x3c014380  lui         $at, 0x4380
    ctx->pc = 0x121580u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17280 << 16));
    // 0x121584: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x121584u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121588: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x121588u;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
    // 0x12158c: 0x46140836  c.le.s      $f1, $f20
    ctx->pc = 0x12158cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x121590: 0x45000015  bc1f        . + 4 + (0x15 << 2)
    ctx->pc = 0x121590u;
    {
        const bool branch_taken_0x121590 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x121594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121590u;
            // 0x121594: 0x3b31021  addu        $v0, $sp, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121590) {
            ctx->pc = 0x1215E8u;
            goto label_1215e8;
        }
    }
    ctx->pc = 0x121598u;
    // 0x121598: 0x3c013b80  lui         $at, 0x3B80
    ctx->pc = 0x121598u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15232 << 16));
    // 0x12159c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12159cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1215a0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1215a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1215a4: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x1215a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1215a8: 0x3b32021  addu        $a0, $sp, $s3
    ctx->pc = 0x1215a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 19)));
    // 0x1215ac: 0x4600a002  mul.s       $f0, $f20, $f0
    ctx->pc = 0x1215acu;
    ctx->f[0] = FPU_MUL_S(ctx->f[20], ctx->f[0]);
    // 0x1215b0: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x1215b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x1215b4: 0x460000a4  .word       0x460000A4                   # cvt.w.s     $f2, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1215b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x1215b8: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x1215b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1215bc: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x1215bcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1215c0: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1215c0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1215c4: 0x46011002  mul.s       $f0, $f2, $f1
    ctx->pc = 0x1215c4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x1215c8: 0x4600a001  sub.s       $f0, $f20, $f0
    ctx->pc = 0x1215c8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
    // 0x1215cc: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1215ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1215d0: 0xe4810000  swc1        $f1, 0x0($a0)
    ctx->pc = 0x1215d0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x1215d4: 0x46001024  .word       0x46001024                   # cvt.w.s     $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1215d4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1215d8: 0xe4600000  swc1        $f0, 0x0($v1)
    ctx->pc = 0x1215d8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x1215dc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1215DCu;
    {
        const bool branch_taken_0x1215dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1215E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1215DCu;
            // 0x1215e0: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1215dc) {
            ctx->pc = 0x1215F0u;
            goto label_1215f0;
        }
    }
    ctx->pc = 0x1215E4u;
    // 0x1215e4: 0x0  nop
    ctx->pc = 0x1215e4u;
    // NOP
label_1215e8:
    // 0x1215e8: 0x4600a024  .word       0x4600A024                   # cvt.w.s     $f0, $f20 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1215e8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[20]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1215ec: 0xe4400000  swc1        $f0, 0x0($v0)
    ctx->pc = 0x1215ecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
label_1215f0:
    // 0x1215f0: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1215f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1215f4: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x1215f4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x1215f8: 0xc0428e0  jal         func_10A380
    ctx->pc = 0x1215F8u;
    SET_GPR_U32(ctx, 31, 0x121600u);
    ctx->pc = 0x1215FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1215F8u;
            // 0x1215fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A380u;
    if (runtime->hasFunction(0x10A380u)) {
        auto targetFn = runtime->lookupFunction(0x10A380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121600u; }
        if (ctx->pc != 0x121600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A380_0x10a380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121600u; }
        if (ctx->pc != 0x121600u) { return; }
    }
    ctx->pc = 0x121600u;
label_121600:
    // 0x121600: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x121600u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121604: 0x4c00011  bltz        $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x121604u;
    {
        const bool branch_taken_0x121604 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x121608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121604u;
            // 0x121608: 0x46000086  mov.s       $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x121604) {
            ctx->pc = 0x12164Cu;
            goto label_12164c;
        }
    }
    ctx->pc = 0x12160Cu;
    // 0x12160c: 0x27a200f0  addiu       $v0, $sp, 0xF0
    ctx->pc = 0x12160cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x121610: 0x3c013b80  lui         $at, 0x3B80
    ctx->pc = 0x121610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15232 << 16));
    // 0x121614: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x121614u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x121618: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12161c: 0x0  nop
    ctx->pc = 0x12161cu;
    // NOP
label_121620:
    // 0x121620: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x121620u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121624: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121624u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121628: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x121628u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x12162c: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x12162cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x121630: 0xc4600000  lwc1        $f0, 0x0($v1)
    ctx->pc = 0x121630u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x121634: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x121634u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x121638: 0x46001002  mul.s       $f0, $f2, $f0
    ctx->pc = 0x121638u;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
    // 0x12163c: 0x46011082  mul.s       $f2, $f2, $f1
    ctx->pc = 0x12163cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x121640: 0x4c1fff7  bgez        $a2, . + 4 + (-0x9 << 2)
    ctx->pc = 0x121640u;
    {
        const bool branch_taken_0x121640 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x121644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121640u;
            // 0x121644: 0xe4400000  swc1        $f0, 0x0($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x121640) {
            ctx->pc = 0x121620u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121620;
        }
    }
    ctx->pc = 0x121648u;
    // 0x121648: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x121648u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_12164c:
    // 0x12164c: 0x4c00024  bltz        $a2, . + 4 + (0x24 << 2)
    ctx->pc = 0x12164Cu;
    {
        const bool branch_taken_0x12164c = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x121650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12164Cu;
            // 0x121650: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12164c) {
            ctx->pc = 0x1216E0u;
            goto label_1216e0;
        }
    }
    ctx->pc = 0x121654u;
    // 0x121654: 0x27a300f0  addiu       $v1, $sp, 0xF0
    ctx->pc = 0x121654u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x121658: 0x60502d  daddu       $t2, $v1, $zero
    ctx->pc = 0x121658u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12165c: 0x244c91b8  addiu       $t4, $v0, -0x6E48
    ctx->pc = 0x12165cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939064));
    // 0x121660: 0x27ab00a0  addiu       $t3, $sp, 0xA0
    ctx->pc = 0x121660u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x121664: 0x0  nop
    ctx->pc = 0x121664u;
    // NOP
label_121668:
    // 0x121668: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x121668u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x12166c: 0x6800016  bltz        $s4, . + 4 + (0x16 << 2)
    ctx->pc = 0x12166Cu;
    {
        const bool branch_taken_0x12166c = (GPR_S64(ctx, 20) < 0);
        ctx->pc = 0x121670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12166Cu;
            // 0x121670: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12166c) {
            ctx->pc = 0x1216C8u;
            goto label_1216c8;
        }
    }
    ctx->pc = 0x121674u;
    // 0x121674: 0x2063823  subu        $a3, $s0, $a2
    ctx->pc = 0x121674u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x121678: 0x4e00014  bltz        $a3, . + 4 + (0x14 << 2)
    ctx->pc = 0x121678u;
    {
        const bool branch_taken_0x121678 = (GPR_S64(ctx, 7) < 0);
        ctx->pc = 0x12167Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121678u;
            // 0x12167c: 0xe0482d  daddu       $t1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121678) {
            ctx->pc = 0x1216CCu;
            goto label_1216cc;
        }
    }
    ctx->pc = 0x121680u;
    // 0x121680: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x121680u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121684: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x121684u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121688: 0x4a2021  addu        $a0, $v0, $t2
    ctx->pc = 0x121688u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x12168c: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x12168cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
label_121690:
    // 0x121690: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x121690u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x121694: 0xc4810000  lwc1        $f1, 0x0($a0)
    ctx->pc = 0x121694u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x121698: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x121698u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x12169c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12169cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1216a0: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1216a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1216a4: 0x288102a  slt         $v0, $s4, $t0
    ctx->pc = 0x1216a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1216a8: 0x128182a  slt         $v1, $t1, $t0
    ctx->pc = 0x1216a8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1216ac: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1216ACu;
    {
        const bool branch_taken_0x1216ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1216B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1216ACu;
            // 0x1216b0: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1216ac) {
            ctx->pc = 0x1216CCu;
            goto label_1216cc;
        }
    }
    ctx->pc = 0x1216B4u;
    // 0x1216b4: 0x5060fff6  beql        $v1, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x1216B4u;
    {
        const bool branch_taken_0x1216b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1216b4) {
            ctx->pc = 0x1216B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1216B4u;
            // 0x1216b8: 0xc4a00000  lwc1        $f0, 0x0($a1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
            ctx->pc = 0x121690u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121690;
        }
    }
    ctx->pc = 0x1216BCu;
    // 0x1216bc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1216BCu;
    {
        const bool branch_taken_0x1216bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1216C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1216BCu;
            // 0x1216c0: 0x71080  sll         $v0, $a3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1216bc) {
            ctx->pc = 0x1216D0u;
            goto label_1216d0;
        }
    }
    ctx->pc = 0x1216C4u;
    // 0x1216c4: 0x0  nop
    ctx->pc = 0x1216c4u;
    // NOP
label_1216c8:
    // 0x1216c8: 0x2063823  subu        $a3, $s0, $a2
    ctx->pc = 0x1216c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
label_1216cc:
    // 0x1216cc: 0x71080  sll         $v0, $a3, 2
    ctx->pc = 0x1216ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
label_1216d0:
    // 0x1216d0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1216d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1216d4: 0x1621021  addu        $v0, $t3, $v0
    ctx->pc = 0x1216d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x1216d8: 0x4c1ffe3  bgez        $a2, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1216D8u;
    {
        const bool branch_taken_0x1216d8 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1216DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1216D8u;
            // 0x1216dc: 0xe4420000  swc1        $f2, 0x0($v0) (Delay Slot)
        { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1216d8) {
            ctx->pc = 0x121668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121668;
        }
    }
    ctx->pc = 0x1216E0u;
label_1216e0:
    // 0x1216e0: 0x8fa50144  lw          $a1, 0x144($sp)
    ctx->pc = 0x1216e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 324)));
    // 0x1216e4: 0x28a20003  slti        $v0, $a1, 0x3
    ctx->pc = 0x1216e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1216e8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1216E8u;
    {
        const bool branch_taken_0x1216e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1216e8) {
            ctx->pc = 0x1216ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1216E8u;
            // 0x1216ec: 0x8fa60144  lw          $a2, 0x144($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 324)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x121708u;
            goto label_121708;
        }
    }
    ctx->pc = 0x1216F0u;
    // 0x1216f0: 0x5ca0001d  bgtzl       $a1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1216F0u;
    {
        const bool branch_taken_0x1216f0 = (GPR_S64(ctx, 5) > 0);
        if (branch_taken_0x1216f0) {
            ctx->pc = 0x1216F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1216F0u;
            // 0x1216f4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x121768u;
            goto label_121768;
        }
    }
    ctx->pc = 0x1216F8u;
    // 0x1216f8: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1216F8u;
    {
        const bool branch_taken_0x1216f8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1216FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1216F8u;
            // 0x1216fc: 0x32a20007  andi        $v0, $s5, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)7);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1216f8) {
            ctx->pc = 0x121720u;
            goto label_121720;
        }
    }
    ctx->pc = 0x121700u;
    // 0x121700: 0x1000007a  b           . + 4 + (0x7A << 2)
    ctx->pc = 0x121700u;
    {
        const bool branch_taken_0x121700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121700u;
            // 0x121704: 0xdfb00150  ld          $s0, 0x150($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 336)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121700) {
            ctx->pc = 0x1218ECu;
            goto label_1218ec;
        }
    }
    ctx->pc = 0x121708u;
label_121708:
    // 0x121708: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x121708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12170c: 0x10c20038  beq         $a2, $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x12170Cu;
    {
        const bool branch_taken_0x12170c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x121710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12170Cu;
            // 0x121710: 0x32a20007  andi        $v0, $s5, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)7);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12170c) {
            ctx->pc = 0x1217F0u;
            goto label_1217f0;
        }
    }
    ctx->pc = 0x121714u;
    // 0x121714: 0x10000075  b           . + 4 + (0x75 << 2)
    ctx->pc = 0x121714u;
    {
        const bool branch_taken_0x121714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121714u;
            // 0x121718: 0xdfb00150  ld          $s0, 0x150($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 336)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121714) {
            ctx->pc = 0x1218ECu;
            goto label_1218ec;
        }
    }
    ctx->pc = 0x12171Cu;
    // 0x12171c: 0x0  nop
    ctx->pc = 0x12171cu;
    // NOP
label_121720:
    // 0x121720: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x121720u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121724: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x121724u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x121728: 0x4c0000a  bltz        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x121728u;
    {
        const bool branch_taken_0x121728 = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x12172Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121728u;
            // 0x12172c: 0x27a300a0  addiu       $v1, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121728) {
            ctx->pc = 0x121754u;
            goto label_121754;
        }
    }
    ctx->pc = 0x121730u;
    // 0x121730: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x121730u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121734: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x121734u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_121738:
    // 0x121738: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x121738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x12173c: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x12173cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x121740: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121740u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121744: 0x0  nop
    ctx->pc = 0x121744u;
    // NOP
    // 0x121748: 0x0  nop
    ctx->pc = 0x121748u;
    // NOP
    // 0x12174c: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x12174Cu;
    {
        const bool branch_taken_0x12174c = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x121750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12174Cu;
            // 0x121750: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12174c) {
            ctx->pc = 0x121738u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121738;
        }
    }
    ctx->pc = 0x121754u;
label_121754:
    // 0x121754: 0x12c00063  beqz        $s6, . + 4 + (0x63 << 2)
    ctx->pc = 0x121754u;
    {
        const bool branch_taken_0x121754 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x121758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121754u;
            // 0x121758: 0xe7c20000  swc1        $f2, 0x0($fp) (Delay Slot)
        { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x121754) {
            ctx->pc = 0x1218E4u;
            goto label_1218e4;
        }
    }
    ctx->pc = 0x12175Cu;
    // 0x12175c: 0x46001007  neg.s       $f0, $f2
    ctx->pc = 0x12175cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[2]);
    // 0x121760: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x121760u;
    {
        const bool branch_taken_0x121760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121760u;
            // 0x121764: 0xe7c00000  swc1        $f0, 0x0($fp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x121760) {
            ctx->pc = 0x1218E4u;
            goto label_1218e4;
        }
    }
    ctx->pc = 0x121768u;
label_121768:
    // 0x121768: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x121768u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x12176c: 0x4c0000b  bltz        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x12176Cu;
    {
        const bool branch_taken_0x12176c = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x121770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12176Cu;
            // 0x121770: 0x27a300a0  addiu       $v1, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12176c) {
            ctx->pc = 0x12179Cu;
            goto label_12179c;
        }
    }
    ctx->pc = 0x121774u;
    // 0x121774: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x121774u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121778: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x121778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12177c: 0x0  nop
    ctx->pc = 0x12177cu;
    // NOP
label_121780:
    // 0x121780: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x121780u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x121784: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x121784u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x121788: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121788u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x12178c: 0x0  nop
    ctx->pc = 0x12178cu;
    // NOP
    // 0x121790: 0x0  nop
    ctx->pc = 0x121790u;
    // NOP
    // 0x121794: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x121794u;
    {
        const bool branch_taken_0x121794 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x121798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121794u;
            // 0x121798: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x121794) {
            ctx->pc = 0x121780u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121780;
        }
    }
    ctx->pc = 0x12179Cu;
label_12179c:
    // 0x12179c: 0x12c00003  beqz        $s6, . + 4 + (0x3 << 2)
    ctx->pc = 0x12179Cu;
    {
        const bool branch_taken_0x12179c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1217A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12179Cu;
            // 0x1217a0: 0xe7c20000  swc1        $f2, 0x0($fp) (Delay Slot)
        { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x12179c) {
            ctx->pc = 0x1217ACu;
            goto label_1217ac;
        }
    }
    ctx->pc = 0x1217A4u;
    // 0x1217a4: 0x46001007  neg.s       $f0, $f2
    ctx->pc = 0x1217a4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[2]);
    // 0x1217a8: 0xe7c00000  swc1        $f0, 0x0($fp)
    ctx->pc = 0x1217a8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 0), bits); }
label_1217ac:
    // 0x1217ac: 0xc7a000a0  lwc1        $f0, 0xA0($sp)
    ctx->pc = 0x1217acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1217b0: 0x1a00000a  blez        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x1217B0u;
    {
        const bool branch_taken_0x1217b0 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x1217B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1217B0u;
            // 0x1217b4: 0x46020081  sub.s       $f2, $f0, $f2 (Delay Slot)
        ctx->f[2] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1217b0) {
            ctx->pc = 0x1217DCu;
            goto label_1217dc;
        }
    }
    ctx->pc = 0x1217B8u;
    // 0x1217b8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1217b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1217bc: 0x27a200a4  addiu       $v0, $sp, 0xA4
    ctx->pc = 0x1217bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
label_1217c0:
    // 0x1217c0: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1217c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1217c4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1217c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1217c8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1217c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1217cc: 0x0  nop
    ctx->pc = 0x1217ccu;
    // NOP
    // 0x1217d0: 0x0  nop
    ctx->pc = 0x1217d0u;
    // NOP
    // 0x1217d4: 0x14c0fffa  bnez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1217D4u;
    {
        const bool branch_taken_0x1217d4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1217D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1217D4u;
            // 0x1217d8: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1217d4) {
            ctx->pc = 0x1217C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1217c0;
        }
    }
    ctx->pc = 0x1217DCu;
label_1217dc:
    // 0x1217dc: 0x12c00041  beqz        $s6, . + 4 + (0x41 << 2)
    ctx->pc = 0x1217DCu;
    {
        const bool branch_taken_0x1217dc = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1217E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1217DCu;
            // 0x1217e0: 0xe7c20004  swc1        $f2, 0x4($fp) (Delay Slot)
        { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 4), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1217dc) {
            ctx->pc = 0x1218E4u;
            goto label_1218e4;
        }
    }
    ctx->pc = 0x1217E4u;
    // 0x1217e4: 0x46001007  neg.s       $f0, $f2
    ctx->pc = 0x1217e4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[2]);
    // 0x1217e8: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1217E8u;
    {
        const bool branch_taken_0x1217e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1217ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1217E8u;
            // 0x1217ec: 0xe7c00004  swc1        $f0, 0x4($fp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 4), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1217e8) {
            ctx->pc = 0x1218E4u;
            goto label_1218e4;
        }
    }
    ctx->pc = 0x1217F0u;
label_1217f0:
    // 0x1217f0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1217f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1217f4: 0x18c00010  blez        $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x1217F4u;
    {
        const bool branch_taken_0x1217f4 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1217F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1217F4u;
            // 0x1217f8: 0x28c20002  slti        $v0, $a2, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1217f4) {
            ctx->pc = 0x121838u;
            goto label_121838;
        }
    }
    ctx->pc = 0x1217FCu;
    // 0x1217fc: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x1217fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121800: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x121800u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x121804: 0x2463009c  addiu       $v1, $v1, 0x9C
    ctx->pc = 0x121804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 156));
label_121808:
    // 0x121808: 0xc4610000  lwc1        $f1, 0x0($v1)
    ctx->pc = 0x121808u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x12180c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x12180cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121810: 0xc4600004  lwc1        $f0, 0x4($v1)
    ctx->pc = 0x121810u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x121814: 0x46000880  add.s       $f2, $f1, $f0
    ctx->pc = 0x121814u;
    ctx->f[2] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x121818: 0x46020841  sub.s       $f1, $f1, $f2
    ctx->pc = 0x121818u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[2]);
    // 0x12181c: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x12181cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x121820: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x121820u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x121824: 0xe4600004  swc1        $f0, 0x4($v1)
    ctx->pc = 0x121824u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x121828: 0x1cc0fff7  bgtz        $a2, . + 4 + (-0x9 << 2)
    ctx->pc = 0x121828u;
    {
        const bool branch_taken_0x121828 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x12182Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121828u;
            // 0x12182c: 0x2463fffc  addiu       $v1, $v1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121828) {
            ctx->pc = 0x121808u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121808;
        }
    }
    ctx->pc = 0x121830u;
    // 0x121830: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x121830u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121834: 0x28c20002  slti        $v0, $a2, 0x2
    ctx->pc = 0x121834u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
label_121838:
    // 0x121838: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x121838u;
    {
        const bool branch_taken_0x121838 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x121838) {
            ctx->pc = 0x12183Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121838u;
            // 0x12183c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x121880u;
            goto label_121880;
        }
    }
    ctx->pc = 0x121840u;
    // 0x121840: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x121840u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x121844: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x121844u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x121848: 0x2463009c  addiu       $v1, $v1, 0x9C
    ctx->pc = 0x121848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 156));
    // 0x12184c: 0x0  nop
    ctx->pc = 0x12184cu;
    // NOP
label_121850:
    // 0x121850: 0xc4600000  lwc1        $f0, 0x0($v1)
    ctx->pc = 0x121850u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x121854: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x121854u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x121858: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x121858u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x12185c: 0x28c20002  slti        $v0, $a2, 0x2
    ctx->pc = 0x12185cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x121860: 0x46010080  add.s       $f2, $f0, $f1
    ctx->pc = 0x121860u;
    ctx->f[2] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x121864: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x121864u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x121868: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x121868u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x12186c: 0x46000840  add.s       $f1, $f1, $f0
    ctx->pc = 0x12186cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x121870: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x121870u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x121874: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x121874u;
    {
        const bool branch_taken_0x121874 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121874u;
            // 0x121878: 0x2463fffc  addiu       $v1, $v1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121874) {
            ctx->pc = 0x121850u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121850;
        }
    }
    ctx->pc = 0x12187Cu;
    // 0x12187c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12187cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_121880:
    // 0x121880: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x121880u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x121884: 0x28c20002  slti        $v0, $a2, 0x2
    ctx->pc = 0x121884u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x121888: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x121888u;
    {
        const bool branch_taken_0x121888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12188Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121888u;
            // 0x12188c: 0x61080  sll         $v0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121888) {
            ctx->pc = 0x1218B4u;
            goto label_1218b4;
        }
    }
    ctx->pc = 0x121890u;
    // 0x121890: 0x27a300a0  addiu       $v1, $sp, 0xA0
    ctx->pc = 0x121890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x121894: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x121894u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_121898:
    // 0x121898: 0xc4600000  lwc1        $f0, 0x0($v1)
    ctx->pc = 0x121898u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x12189c: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x12189cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x1218a0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1218a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1218a4: 0x28c20002  slti        $v0, $a2, 0x2
    ctx->pc = 0x1218a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1218a8: 0x0  nop
    ctx->pc = 0x1218a8u;
    // NOP
    // 0x1218ac: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1218ACu;
    {
        const bool branch_taken_0x1218ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1218B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1218ACu;
            // 0x1218b0: 0x46001080  add.s       $f2, $f2, $f0 (Delay Slot)
        ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1218ac) {
            ctx->pc = 0x121898u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_121898;
        }
    }
    ctx->pc = 0x1218B4u;
label_1218b4:
    // 0x1218b4: 0x16c00004  bnez        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1218B4u;
    {
        const bool branch_taken_0x1218b4 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        ctx->pc = 0x1218B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1218B4u;
            // 0x1218b8: 0xc7a000a0  lwc1        $f0, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1218b4) {
            ctx->pc = 0x1218C8u;
            goto label_1218c8;
        }
    }
    ctx->pc = 0x1218BCu;
    // 0x1218bc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1218BCu;
    {
        const bool branch_taken_0x1218bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1218C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1218BCu;
            // 0x1218c0: 0xc7a100a4  lwc1        $f1, 0xA4($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1218bc) {
            ctx->pc = 0x1218D8u;
            goto label_1218d8;
        }
    }
    ctx->pc = 0x1218C4u;
    // 0x1218c4: 0x0  nop
    ctx->pc = 0x1218c4u;
    // NOP
label_1218c8:
    // 0x1218c8: 0x46001087  neg.s       $f2, $f2
    ctx->pc = 0x1218c8u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x1218cc: 0xc7a100a4  lwc1        $f1, 0xA4($sp)
    ctx->pc = 0x1218ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1218d0: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x1218d0u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x1218d4: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x1218d4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
label_1218d8:
    // 0x1218d8: 0xe7c20008  swc1        $f2, 0x8($fp)
    ctx->pc = 0x1218d8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 8), bits); }
    // 0x1218dc: 0xe7c00000  swc1        $f0, 0x0($fp)
    ctx->pc = 0x1218dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 0), bits); }
    // 0x1218e0: 0xe7c10004  swc1        $f1, 0x4($fp)
    ctx->pc = 0x1218e0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 4), bits); }
label_1218e4:
    // 0x1218e4: 0x32a20007  andi        $v0, $s5, 0x7
    ctx->pc = 0x1218e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)7);
    // 0x1218e8: 0xdfb00150  ld          $s0, 0x150($sp)
    ctx->pc = 0x1218e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 336)));
label_1218ec:
    // 0x1218ec: 0xdfb10158  ld          $s1, 0x158($sp)
    ctx->pc = 0x1218ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 344)));
    // 0x1218f0: 0xdfb20160  ld          $s2, 0x160($sp)
    ctx->pc = 0x1218f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x1218f4: 0xdfb30168  ld          $s3, 0x168($sp)
    ctx->pc = 0x1218f4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 360)));
    // 0x1218f8: 0xdfb40170  ld          $s4, 0x170($sp)
    ctx->pc = 0x1218f8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 368)));
    // 0x1218fc: 0xdfb50178  ld          $s5, 0x178($sp)
    ctx->pc = 0x1218fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 376)));
    // 0x121900: 0xdfb60180  ld          $s6, 0x180($sp)
    ctx->pc = 0x121900u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 384)));
    // 0x121904: 0xdfb70188  ld          $s7, 0x188($sp)
    ctx->pc = 0x121904u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 392)));
    // 0x121908: 0xdfbe0190  ld          $fp, 0x190($sp)
    ctx->pc = 0x121908u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 400)));
    // 0x12190c: 0xdfbf0198  ld          $ra, 0x198($sp)
    ctx->pc = 0x12190cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 408)));
    // 0x121910: 0xc7b401a0  lwc1        $f20, 0x1A0($sp)
    ctx->pc = 0x121910u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 416)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x121914: 0x3e00008  jr          $ra
    ctx->pc = 0x121914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x121918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121914u;
            // 0x121918: 0x27bd01b0  addiu       $sp, $sp, 0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 432));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x121150u: goto label_121150;
            case 0x121164u: goto label_121164;
            case 0x121178u: goto label_121178;
            case 0x121190u: goto label_121190;
            case 0x1211B0u: goto label_1211b0;
            case 0x1211D4u: goto label_1211d4;
            case 0x1211E8u: goto label_1211e8;
            case 0x1211ECu: goto label_1211ec;
            case 0x121220u: goto label_121220;
            case 0x12125Cu: goto label_12125c;
            case 0x121268u: goto label_121268;
            case 0x121280u: goto label_121280;
            case 0x1212E0u: goto label_1212e0;
            case 0x1212F8u: goto label_1212f8;
            case 0x12130Cu: goto label_12130c;
            case 0x121330u: goto label_121330;
            case 0x121348u: goto label_121348;
            case 0x12134Cu: goto label_12134c;
            case 0x121350u: goto label_121350;
            case 0x121364u: goto label_121364;
            case 0x121388u: goto label_121388;
            case 0x1213A0u: goto label_1213a0;
            case 0x1213ACu: goto label_1213ac;
            case 0x1213B4u: goto label_1213b4;
            case 0x1213D4u: goto label_1213d4;
            case 0x1213D8u: goto label_1213d8;
            case 0x121400u: goto label_121400;
            case 0x12141Cu: goto label_12141c;
            case 0x121448u: goto label_121448;
            case 0x121464u: goto label_121464;
            case 0x1214B0u: goto label_1214b0;
            case 0x1214D8u: goto label_1214d8;
            case 0x1214F8u: goto label_1214f8;
            case 0x121520u: goto label_121520;
            case 0x121528u: goto label_121528;
            case 0x121550u: goto label_121550;
            case 0x121578u: goto label_121578;
            case 0x121580u: goto label_121580;
            case 0x1215E8u: goto label_1215e8;
            case 0x1215F0u: goto label_1215f0;
            case 0x121600u: goto label_121600;
            case 0x121620u: goto label_121620;
            case 0x12164Cu: goto label_12164c;
            case 0x121668u: goto label_121668;
            case 0x121690u: goto label_121690;
            case 0x1216C8u: goto label_1216c8;
            case 0x1216CCu: goto label_1216cc;
            case 0x1216D0u: goto label_1216d0;
            case 0x1216E0u: goto label_1216e0;
            case 0x121708u: goto label_121708;
            case 0x121720u: goto label_121720;
            case 0x121738u: goto label_121738;
            case 0x121754u: goto label_121754;
            case 0x121768u: goto label_121768;
            case 0x121780u: goto label_121780;
            case 0x12179Cu: goto label_12179c;
            case 0x1217ACu: goto label_1217ac;
            case 0x1217C0u: goto label_1217c0;
            case 0x1217DCu: goto label_1217dc;
            case 0x1217F0u: goto label_1217f0;
            case 0x121808u: goto label_121808;
            case 0x121838u: goto label_121838;
            case 0x121850u: goto label_121850;
            case 0x121880u: goto label_121880;
            case 0x121898u: goto label_121898;
            case 0x1218B4u: goto label_1218b4;
            case 0x1218C8u: goto label_1218c8;
            case 0x1218D8u: goto label_1218d8;
            case 0x1218E4u: goto label_1218e4;
            case 0x1218ECu: goto label_1218ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12191Cu;
    // 0x12191c: 0x0  nop
    ctx->pc = 0x12191cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

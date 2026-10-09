#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001273F0
// Address: 0x1273f0 - 0x127690
void sub_001273F0_0x1273f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001273F0_0x1273f0");
#endif

    switch (ctx->pc) {
        case 0x1274a8u: goto label_1274a8;
        case 0x127540u: goto label_127540;
        default: break;
    }

    ctx->pc = 0x1273f0u;

    // 0x1273f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1273f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1273f4: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x1273f4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x1273f8: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x1273f8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x1273fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1273fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127400: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x127400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x127404: 0xa5303  sra         $t2, $t2, 12
    ctx->pc = 0x127404u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127408: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x127408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12740c: 0xb5b03  sra         $t3, $t3, 12
    ctx->pc = 0x12740cu;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127410: 0xa0c02d  daddu       $t8, $a1, $zero
    ctx->pc = 0x127410u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127414: 0xe0702d  daddu       $t6, $a3, $zero
    ctx->pc = 0x127414u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127418: 0x120782d  daddu       $t7, $t1, $zero
    ctx->pc = 0x127418u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12741c: 0x448a1000  mtc1        $t2, $f2
    ctx->pc = 0x12741cu;
    { uint32_t bits = GPR_U32(ctx, 10); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x127420: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x127420u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x127424: 0x448b0800  mtc1        $t3, $f1
    ctx->pc = 0x127424u;
    { uint32_t bits = GPR_U32(ctx, 11); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x127428: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x127428u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x12742c: 0x85c30000  lh          $v1, 0x0($t6)
    ctx->pc = 0x12742cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x127430: 0x85c70002  lh          $a3, 0x2($t6)
    ctx->pc = 0x127430u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x127434: 0x1817c2  srl         $v0, $t8, 31
    ctx->pc = 0x127434u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 24), 31));
    // 0x127438: 0x85e90000  lh          $t1, 0x0($t7)
    ctx->pc = 0x127438u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x12743c: 0x3021021  addu        $v0, $t8, $v0
    ctx->pc = 0x12743cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
    // 0x127440: 0x85e50002  lh          $a1, 0x2($t7)
    ctx->pc = 0x127440u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 2)));
    // 0x127444: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x127444u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x127448: 0x3c013780  lui         $at, 0x3780
    ctx->pc = 0x127448u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14208 << 16));
    // 0x12744c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12744cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x127450: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x127450u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x127454: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x127454u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x127458: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x127458u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x12745c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x12745cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x127460: 0x46000b82  mul.s       $f14, $f1, $f0
    ctx->pc = 0x127460u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x127464: 0x44834800  mtc1        $v1, $f9
    ctx->pc = 0x127464u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x127468: 0x46804a60  cvt.s.w     $f9, $f9
    ctx->pc = 0x127468u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[9], sizeof(tmp)); ctx->f[9] = FPU_CVT_S_W(tmp); }
    // 0x12746c: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x12746cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127470: 0x44875800  mtc1        $a3, $f11
    ctx->pc = 0x127470u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[11], &bits, sizeof(bits)); }
    // 0x127474: 0x46805ae0  cvt.s.w     $f11, $f11
    ctx->pc = 0x127474u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[11], sizeof(tmp)); ctx->f[11] = FPU_CVT_S_W(tmp); }
    // 0x127478: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x127478u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12747c: 0x44894000  mtc1        $t1, $f8
    ctx->pc = 0x12747cu;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x127480: 0x46804220  cvt.s.w     $f8, $f8
    ctx->pc = 0x127480u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[8], sizeof(tmp)); ctx->f[8] = FPU_CVT_S_W(tmp); }
    // 0x127484: 0x44855000  mtc1        $a1, $f10
    ctx->pc = 0x127484u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x127488: 0x468052a0  cvt.s.w     $f10, $f10
    ctx->pc = 0x127488u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[10], sizeof(tmp)); ctx->f[10] = FPU_CVT_S_W(tmp); }
    // 0x12748c: 0x1840006a  blez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x12748Cu;
    {
        const bool branch_taken_0x12748c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x127490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12748Cu;
            // 0x127490: 0x46001302  mul.s       $f12, $f2, $f0 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12748c) {
            ctx->pc = 0x127638u;
            goto label_127638;
        }
    }
    ctx->pc = 0x127494u;
    // 0x127494: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x127494u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127498: 0x2419ff00  addiu       $t9, $zero, -0x100
    ctx->pc = 0x127498u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x12749c: 0x3c120024  lui         $s2, 0x24
    ctx->pc = 0x12749cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
    // 0x1274a0: 0x3c110024  lui         $s1, 0x24
    ctx->pc = 0x1274a0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)36 << 16));
    // 0x1274a4: 0x140382d  daddu       $a3, $t2, $zero
    ctx->pc = 0x1274a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_1274a8:
    // 0x1274a8: 0x254a0012  addiu       $t2, $t2, 0x12
    ctx->pc = 0x1274a8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 18));
    // 0x1274ac: 0x94e30000  lhu         $v1, 0x0($a3)
    ctx->pc = 0x1274acu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1274b0: 0x90e40001  lbu         $a0, 0x1($a3)
    ctx->pc = 0x1274b0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1274b4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1274b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274b8: 0x791824  and         $v1, $v1, $t9
    ctx->pc = 0x1274b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 25));
    // 0x1274bc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1274bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1274c0: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1274c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274c4: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1274c4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1274c8: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x1274c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x1274cc: 0x1460006b  bnez        $v1, . + 4 + (0x6B << 2)
    ctx->pc = 0x1274CCu;
    {
        const bool branch_taken_0x1274cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1274D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1274CCu;
            // 0x1274d0: 0xd1040  sll         $v0, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1274cc) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x1274D4u;
    // 0x1274d4: 0x95430000  lhu         $v1, 0x0($t2)
    ctx->pc = 0x1274d4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1274d8: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x1274d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x1274dc: 0x91440001  lbu         $a0, 0x1($t2)
    ctx->pc = 0x1274dcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x1274e0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1274e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1274e4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1274e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274e8: 0x44827800  mtc1        $v0, $f15
    ctx->pc = 0x1274e8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[15], &bits, sizeof(bits)); }
    // 0x1274ec: 0x46807be0  cvt.s.w     $f15, $f15
    ctx->pc = 0x1274ecu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[15], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x1274f0: 0x791824  and         $v1, $v1, $t9
    ctx->pc = 0x1274f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 25));
    // 0x1274f4: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1274f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1274f8: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1274f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274fc: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1274fcu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127500: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127500u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127504: 0x1460005d  bnez        $v1, . + 4 + (0x5D << 2)
    ctx->pc = 0x127504u;
    {
        const bool branch_taken_0x127504 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127504u;
            // 0x127508: 0xd1040  sll         $v0, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127504) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x12750Cu;
    // 0x12750c: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x12750cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127510: 0x3c013f33  lui         $at, 0x3F33
    ctx->pc = 0x127510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16179 << 16));
    // 0x127514: 0x34213333  ori         $at, $at, 0x3333
    ctx->pc = 0x127514u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)13107);
    // 0x127518: 0x44818000  mtc1        $at, $f16
    ctx->pc = 0x127518u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[16], &bits, sizeof(bits)); }
    // 0x12751c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12751cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127520: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x127520u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x127524: 0x44826800  mtc1        $v0, $f13
    ctx->pc = 0x127524u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[13], &bits, sizeof(bits)); }
    // 0x127528: 0x46806b60  cvt.s.w     $f13, $f13
    ctx->pc = 0x127528u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[13], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x12752c: 0x254a0002  addiu       $t2, $t2, 0x2
    ctx->pc = 0x12752cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 2));
    // 0x127530: 0x264ca528  addiu       $t4, $s2, -0x5AD8
    ctx->pc = 0x127530u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 18), 4294944040));
    // 0x127534: 0x262ba928  addiu       $t3, $s1, -0x56D8
    ctx->pc = 0x127534u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 17), 4294945064));
    // 0x127538: 0x2409001e  addiu       $t1, $zero, 0x1E
    ctx->pc = 0x127538u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x12753c: 0x0  nop
    ctx->pc = 0x12753cu;
    // NOP
label_127540:
    // 0x127540: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x127540u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127544: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x127544u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x127548: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x127548u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x12754c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x12754cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x127550: 0x460b7042  mul.s       $f1, $f14, $f11
    ctx->pc = 0x127550u;
    ctx->f[1] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127554: 0x46004ac6  mov.s       $f11, $f9
    ctx->pc = 0x127554u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x127558: 0x460a70c2  mul.s       $f3, $f14, $f10
    ctx->pc = 0x127558u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x12755c: 0x46004286  mov.s       $f10, $f8
    ctx->pc = 0x12755cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x127560: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x127560u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x127564: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x127564u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x127568: 0x46096082  mul.s       $f2, $f12, $f9
    ctx->pc = 0x127568u;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x12756c: 0x4c2021  addu        $a0, $v0, $t4
    ctx->pc = 0x12756cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x127570: 0x46086002  mul.s       $f0, $f12, $f8
    ctx->pc = 0x127570u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x127574: 0x6c2821  addu        $a1, $v1, $t4
    ctx->pc = 0x127574u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x127578: 0xc4870000  lwc1        $f7, 0x0($a0)
    ctx->pc = 0x127578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x12757c: 0x460b7182  mul.s       $f6, $f14, $f11
    ctx->pc = 0x12757cu;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127580: 0xc4a40000  lwc1        $f4, 0x0($a1)
    ctx->pc = 0x127580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x127584: 0x460a7142  mul.s       $f5, $f14, $f10
    ctx->pc = 0x127584u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127588: 0x46011080  add.s       $f2, $f2, $f1
    ctx->pc = 0x127588u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x12758c: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x12758cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x127590: 0x46030000  add.s       $f0, $f0, $f3
    ctx->pc = 0x127590u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x127594: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x127594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x127598: 0x460f38c2  mul.s       $f3, $f7, $f15
    ctx->pc = 0x127598u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x12759c: 0xc4470000  lwc1        $f7, 0x0($v0)
    ctx->pc = 0x12759cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1275a0: 0x460d2042  mul.s       $f1, $f4, $f13
    ctx->pc = 0x1275a0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275a4: 0xc4640000  lwc1        $f4, 0x0($v1)
    ctx->pc = 0x1275a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1275a8: 0x2529fffe  addiu       $t1, $t1, -0x2
    ctx->pc = 0x1275a8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967294));
    // 0x1275ac: 0x460d2102  mul.s       $f4, $f4, $f13
    ctx->pc = 0x1275acu;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275b0: 0x46031240  add.s       $f9, $f2, $f3
    ctx->pc = 0x1275b0u;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275b4: 0x46010200  add.s       $f8, $f0, $f1
    ctx->pc = 0x1275b4u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1275b8: 0x460f38c2  mul.s       $f3, $f7, $f15
    ctx->pc = 0x1275b8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x1275bc: 0x46096082  mul.s       $f2, $f12, $f9
    ctx->pc = 0x1275bcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x1275c0: 0x46004ac6  mov.s       $f11, $f9
    ctx->pc = 0x1275c0u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x1275c4: 0x46086042  mul.s       $f1, $f12, $f8
    ctx->pc = 0x1275c4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x1275c8: 0x46004286  mov.s       $f10, $f8
    ctx->pc = 0x1275c8u;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x1275cc: 0x46084800  add.s       $f0, $f9, $f8
    ctx->pc = 0x1275ccu;
    ctx->f[0] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275d0: 0x46061080  add.s       $f2, $f2, $f6
    ctx->pc = 0x1275d0u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[6]);
    // 0x1275d4: 0x46050840  add.s       $f1, $f1, $f5
    ctx->pc = 0x1275d4u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x1275d8: 0x46100002  mul.s       $f0, $f0, $f16
    ctx->pc = 0x1275d8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[16]);
    // 0x1275dc: 0x46031240  add.s       $f9, $f2, $f3
    ctx->pc = 0x1275dcu;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275e0: 0x46040a00  add.s       $f8, $f1, $f4
    ctx->pc = 0x1275e0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x1275e4: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1275e4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1275e8: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x1275e8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1275ec: 0x46084840  add.s       $f1, $f9, $f8
    ctx->pc = 0x1275ecu;
    ctx->f[1] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275f0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1275f0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1275f4: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x1275f4u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1275f8: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x1275f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x1275fc: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x1275fcu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127600: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127604: 0x46100842  mul.s       $f1, $f1, $f16
    ctx->pc = 0x127604u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[16]);
    // 0x127608: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127608u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12760c: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x12760cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x127610: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x127610u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x127614: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x127614u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127618: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127618u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x12761c: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x12761cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127620: 0x521ffc7  bgez        $t1, . + 4 + (-0x39 << 2)
    ctx->pc = 0x127620u;
    {
        const bool branch_taken_0x127620 = (GPR_S64(ctx, 9) >= 0);
        ctx->pc = 0x127624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127620u;
            // 0x127624: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127620) {
            ctx->pc = 0x127540u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127540;
        }
    }
    ctx->pc = 0x127628u;
    // 0x127628: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x127628u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x12762c: 0x1b0102a  slt         $v0, $t5, $s0
    ctx->pc = 0x12762cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x127630: 0x1440ff9d  bnez        $v0, . + 4 + (-0x63 << 2)
    ctx->pc = 0x127630u;
    {
        const bool branch_taken_0x127630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127630u;
            // 0x127634: 0x140382d  daddu       $a3, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127630) {
            ctx->pc = 0x1274A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1274a8;
        }
    }
    ctx->pc = 0x127638u;
label_127638:
    // 0x127638: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127638u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12763c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12763cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127640: 0x300102d  daddu       $v0, $t8, $zero
    ctx->pc = 0x127640u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127644: 0x46005824  .word       0x46005824                   # cvt.w.s     $f0, $f11 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127644u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[11]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127648: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x127648u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x12764c: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x12764cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127650: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x127650u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x127654: 0x46005024  .word       0x46005024                   # cvt.w.s     $f0, $f10 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127654u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[10]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127658: 0x44060000  mfc1        $a2, $f0
    ctx->pc = 0x127658u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x12765c: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x12765cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127660: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x127660u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127664: 0xa5c30000  sh          $v1, 0x0($t6)
    ctx->pc = 0x127664u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x127668: 0x52c03  sra         $a1, $a1, 16
    ctx->pc = 0x127668u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x12766c: 0xa5c40002  sh          $a0, 0x2($t6)
    ctx->pc = 0x12766cu;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x127670: 0x63403  sra         $a2, $a2, 16
    ctx->pc = 0x127670u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x127674: 0xa5e50000  sh          $a1, 0x0($t7)
    ctx->pc = 0x127674u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x127678: 0xa5e60002  sh          $a2, 0x2($t7)
    ctx->pc = 0x127678u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 2), (uint16_t)GPR_U32(ctx, 6));
label_12767c:
    // 0x12767c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12767cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127680: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x127680u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127684: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x127684u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127688: 0x3e00008  jr          $ra
    ctx->pc = 0x127688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12768Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127688u;
            // 0x12768c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127690u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

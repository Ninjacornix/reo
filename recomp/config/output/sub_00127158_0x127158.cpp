#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00127158
// Address: 0x127158 - 0x1273ec
void sub_00127158_0x127158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00127158_0x127158");
#endif

    switch (ctx->pc) {
        case 0x127210u: goto label_127210;
        case 0x127298u: goto label_127298;
        default: break;
    }

    ctx->pc = 0x127158u;

    // 0x127158: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x127158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12715c: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x12715cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127160: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127160u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x127164: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x127164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x127168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12716c: 0xa5303  sra         $t2, $t2, 12
    ctx->pc = 0x12716cu;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127170: 0xb5b03  sra         $t3, $t3, 12
    ctx->pc = 0x127170u;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127174: 0xa0782d  daddu       $t7, $a1, $zero
    ctx->pc = 0x127174u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127178: 0xe0682d  daddu       $t5, $a3, $zero
    ctx->pc = 0x127178u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12717c: 0x120702d  daddu       $t6, $t1, $zero
    ctx->pc = 0x12717cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127180: 0x448a1000  mtc1        $t2, $f2
    ctx->pc = 0x127180u;
    { uint32_t bits = GPR_U32(ctx, 10); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x127184: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x127184u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x127188: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x127188u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12718c: 0x448b0800  mtc1        $t3, $f1
    ctx->pc = 0x12718cu;
    { uint32_t bits = GPR_U32(ctx, 11); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x127190: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x127190u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x127194: 0x85a30000  lh          $v1, 0x0($t5)
    ctx->pc = 0x127194u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x127198: 0x85a70002  lh          $a3, 0x2($t5)
    ctx->pc = 0x127198u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 2)));
    // 0x12719c: 0xf17c2  srl         $v0, $t7, 31
    ctx->pc = 0x12719cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 15), 31));
    // 0x1271a0: 0x85c90000  lh          $t1, 0x0($t6)
    ctx->pc = 0x1271a0u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1271a4: 0x1e21021  addu        $v0, $t7, $v0
    ctx->pc = 0x1271a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 2)));
    // 0x1271a8: 0x85c50002  lh          $a1, 0x2($t6)
    ctx->pc = 0x1271a8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x1271ac: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1271acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1271b0: 0x3c013780  lui         $at, 0x3780
    ctx->pc = 0x1271b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14208 << 16));
    // 0x1271b4: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1271b4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1271b8: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x1271b8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1271bc: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x1271bcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x1271c0: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1271c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1271c4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1271c4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1271c8: 0x46000b82  mul.s       $f14, $f1, $f0
    ctx->pc = 0x1271c8u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1271cc: 0x44834000  mtc1        $v1, $f8
    ctx->pc = 0x1271ccu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x1271d0: 0x46804220  cvt.s.w     $f8, $f8
    ctx->pc = 0x1271d0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[8], sizeof(tmp)); ctx->f[8] = FPU_CVT_S_W(tmp); }
    // 0x1271d4: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x1271d4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271d8: 0x44875800  mtc1        $a3, $f11
    ctx->pc = 0x1271d8u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[11], &bits, sizeof(bits)); }
    // 0x1271dc: 0x46805ae0  cvt.s.w     $f11, $f11
    ctx->pc = 0x1271dcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[11], sizeof(tmp)); ctx->f[11] = FPU_CVT_S_W(tmp); }
    // 0x1271e0: 0x44894800  mtc1        $t1, $f9
    ctx->pc = 0x1271e0u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x1271e4: 0x46804a60  cvt.s.w     $f9, $f9
    ctx->pc = 0x1271e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[9], sizeof(tmp)); ctx->f[9] = FPU_CVT_S_W(tmp); }
    // 0x1271e8: 0x44855000  mtc1        $a1, $f10
    ctx->pc = 0x1271e8u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x1271ec: 0x468052a0  cvt.s.w     $f10, $f10
    ctx->pc = 0x1271ecu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[10], sizeof(tmp)); ctx->f[10] = FPU_CVT_S_W(tmp); }
    // 0x1271f0: 0x18400069  blez        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x1271F0u;
    {
        const bool branch_taken_0x1271f0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1271F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1271F0u;
            // 0x1271f4: 0x46001342  mul.s       $f13, $f2, $f0 (Delay Slot)
        ctx->f[13] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1271f0) {
            ctx->pc = 0x127398u;
            goto label_127398;
        }
    }
    ctx->pc = 0x1271F8u;
    // 0x1271f8: 0x40c82d  daddu       $t9, $v0, $zero
    ctx->pc = 0x1271f8u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271fc: 0x2418ff00  addiu       $t8, $zero, -0x100
    ctx->pc = 0x1271fcu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127200: 0x3c110024  lui         $s1, 0x24
    ctx->pc = 0x127200u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)36 << 16));
    // 0x127204: 0x3c100024  lui         $s0, 0x24
    ctx->pc = 0x127204u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
    // 0x127208: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x127208u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12720c: 0x0  nop
    ctx->pc = 0x12720cu;
    // NOP
label_127210:
    // 0x127210: 0x254a0012  addiu       $t2, $t2, 0x12
    ctx->pc = 0x127210u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 18));
    // 0x127214: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x127214u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x127218: 0x90a40001  lbu         $a0, 0x1($a1)
    ctx->pc = 0x127218u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x12721c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12721cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127220: 0x781824  and         $v1, $v1, $t8
    ctx->pc = 0x127220u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 24));
    // 0x127224: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127224u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127228: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127228u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12722c: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x12722cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127230: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127230u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127234: 0x14600069  bnez        $v1, . + 4 + (0x69 << 2)
    ctx->pc = 0x127234u;
    {
        const bool branch_taken_0x127234 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127234u;
            // 0x127238: 0xc1040  sll         $v0, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127234) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x12723Cu;
    // 0x12723c: 0x95430000  lhu         $v1, 0x0($t2)
    ctx->pc = 0x12723cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x127240: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x127240u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127244: 0x91440001  lbu         $a0, 0x1($t2)
    ctx->pc = 0x127244u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x127248: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x127248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12724c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12724cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127250: 0x44827800  mtc1        $v0, $f15
    ctx->pc = 0x127250u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[15], &bits, sizeof(bits)); }
    // 0x127254: 0x46807be0  cvt.s.w     $f15, $f15
    ctx->pc = 0x127254u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[15], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x127258: 0x781824  and         $v1, $v1, $t8
    ctx->pc = 0x127258u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 24));
    // 0x12725c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x12725cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127260: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127260u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x127264: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x127264u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127268: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127268u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x12726c: 0x1460005b  bnez        $v1, . + 4 + (0x5B << 2)
    ctx->pc = 0x12726Cu;
    {
        const bool branch_taken_0x12726c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12726Cu;
            // 0x127270: 0xc1040  sll         $v0, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12726c) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x127274u;
    // 0x127274: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x127274u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127278: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x127278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x12727c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12727cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127280: 0x254a0002  addiu       $t2, $t2, 0x2
    ctx->pc = 0x127280u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 2));
    // 0x127284: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x127284u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x127288: 0x46806320  cvt.s.w     $f12, $f12
    ctx->pc = 0x127288u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[12], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x12728c: 0x262ba528  addiu       $t3, $s1, -0x5AD8
    ctx->pc = 0x12728cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 17), 4294944040));
    // 0x127290: 0x2609a928  addiu       $t1, $s0, -0x56D8
    ctx->pc = 0x127290u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945064));
    // 0x127294: 0x2407001e  addiu       $a3, $zero, 0x1E
    ctx->pc = 0x127294u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
label_127298:
    // 0x127298: 0x90a40000  lbu         $a0, 0x0($a1)
    ctx->pc = 0x127298u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12729c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12729cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1272a0: 0x460b7082  mul.s       $f2, $f14, $f11
    ctx->pc = 0x1272a0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272a4: 0x460042c6  mov.s       $f11, $f8
    ctx->pc = 0x1272a4u;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x1272a8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1272a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1272ac: 0x46086802  mul.s       $f0, $f13, $f8
    ctx->pc = 0x1272acu;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x1272b0: 0x8b1021  addu        $v0, $a0, $t3
    ctx->pc = 0x1272b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1272b4: 0x892021  addu        $a0, $a0, $t1
    ctx->pc = 0x1272b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1272b8: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x1272b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1272bc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1272bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1272c0: 0xc4440000  lwc1        $f4, 0x0($v0)
    ctx->pc = 0x1272c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272c4: 0x460a70c2  mul.s       $f3, $f14, $f10
    ctx->pc = 0x1272c4u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x1272c8: 0x46020000  add.s       $f0, $f0, $f2
    ctx->pc = 0x1272c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272cc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1272ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1272d0: 0x460f2082  mul.s       $f2, $f4, $f15
    ctx->pc = 0x1272d0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x1272d4: 0xc4840000  lwc1        $f4, 0x0($a0)
    ctx->pc = 0x1272d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272d8: 0x46096842  mul.s       $f1, $f13, $f9
    ctx->pc = 0x1272d8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x1272dc: 0x6b1021  addu        $v0, $v1, $t3
    ctx->pc = 0x1272dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x1272e0: 0xc4470000  lwc1        $f7, 0x0($v0)
    ctx->pc = 0x1272e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1272e4: 0x46004a86  mov.s       $f10, $f9
    ctx->pc = 0x1272e4u;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x1272e8: 0x460b7182  mul.s       $f6, $f14, $f11
    ctx->pc = 0x1272e8u;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272ec: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1272ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1272f0: 0x46020200  add.s       $f8, $f0, $f2
    ctx->pc = 0x1272f0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272f4: 0x24e7fffe  addiu       $a3, $a3, -0x2
    ctx->pc = 0x1272f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967294));
    // 0x1272f8: 0x46030840  add.s       $f1, $f1, $f3
    ctx->pc = 0x1272f8u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x1272fc: 0x460c38c2  mul.s       $f3, $f7, $f12
    ctx->pc = 0x1272fcu;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127300: 0xc4670000  lwc1        $f7, 0x0($v1)
    ctx->pc = 0x127300u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x127304: 0x460a7142  mul.s       $f5, $f14, $f10
    ctx->pc = 0x127304u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127308: 0x46086802  mul.s       $f0, $f13, $f8
    ctx->pc = 0x127308u;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x12730c: 0x460042c6  mov.s       $f11, $f8
    ctx->pc = 0x12730cu;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x127310: 0x460f2102  mul.s       $f4, $f4, $f15
    ctx->pc = 0x127310u;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x127314: 0x46030a40  add.s       $f9, $f1, $f3
    ctx->pc = 0x127314u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x127318: 0x46004064  .word       0x46004064                   # cvt.w.s     $f1, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127318u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x12731c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x12731cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127320: 0x46060000  add.s       $f0, $f0, $f6
    ctx->pc = 0x127320u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x127324: 0x460c3882  mul.s       $f2, $f7, $f12
    ctx->pc = 0x127324u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127328: 0x46096842  mul.s       $f1, $f13, $f9
    ctx->pc = 0x127328u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x12732c: 0x46004a86  mov.s       $f10, $f9
    ctx->pc = 0x12732cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x127330: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127330u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127334: 0x460048e4  .word       0x460048E4                   # cvt.w.s     $f3, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127334u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x127338: 0x44031800  mfc1        $v1, $f3
    ctx->pc = 0x127338u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x12733c: 0x46040200  add.s       $f8, $f0, $f4
    ctx->pc = 0x12733cu;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[4]);
    // 0x127340: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x127340u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127344: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127344u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127348: 0x46050840  add.s       $f1, $f1, $f5
    ctx->pc = 0x127348u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x12734c: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x12734cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127350: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x127350u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127354: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127354u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x127358: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127358u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12735c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12735cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127360: 0x46020a40  add.s       $f9, $f1, $f2
    ctx->pc = 0x127360u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x127364: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127364u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127368: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127368u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12736c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12736cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127370: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x127370u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127374: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127378: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127378u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x12737c: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x12737cu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127380: 0x4e1ffc5  bgez        $a3, . + 4 + (-0x3B << 2)
    ctx->pc = 0x127380u;
    {
        const bool branch_taken_0x127380 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x127384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127380u;
            // 0x127384: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127380) {
            ctx->pc = 0x127298u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127298;
        }
    }
    ctx->pc = 0x127388u;
    // 0x127388: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x127388u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x12738c: 0x199102a  slt         $v0, $t4, $t9
    ctx->pc = 0x12738cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 25)) ? 1 : 0);
    // 0x127390: 0x1440ff9f  bnez        $v0, . + 4 + (-0x61 << 2)
    ctx->pc = 0x127390u;
    {
        const bool branch_taken_0x127390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127390u;
            // 0x127394: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127390) {
            ctx->pc = 0x127210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127210;
        }
    }
    ctx->pc = 0x127398u;
label_127398:
    // 0x127398: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127398u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12739c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12739cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1273a0: 0x1e0102d  daddu       $v0, $t7, $zero
    ctx->pc = 0x1273a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1273a4: 0x46005824  .word       0x46005824                   # cvt.w.s     $f0, $f11 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273a4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[11]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273a8: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x1273a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1273ac: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273acu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273b0: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1273b0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1273b4: 0x46005024  .word       0x46005024                   # cvt.w.s     $f0, $f10 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[10]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273b8: 0x44060000  mfc1        $a2, $f0
    ctx->pc = 0x1273b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x1273bc: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x1273bcu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x1273c0: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1273c0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1273c4: 0xa5a30000  sh          $v1, 0x0($t5)
    ctx->pc = 0x1273c4u;
    WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1273c8: 0x52c03  sra         $a1, $a1, 16
    ctx->pc = 0x1273c8u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x1273cc: 0xa5a40002  sh          $a0, 0x2($t5)
    ctx->pc = 0x1273ccu;
    WRITE16(ADD32(GPR_U32(ctx, 13), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1273d0: 0x63403  sra         $a2, $a2, 16
    ctx->pc = 0x1273d0u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x1273d4: 0xa5c50000  sh          $a1, 0x0($t6)
    ctx->pc = 0x1273d4u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1273d8: 0xa5c60002  sh          $a2, 0x2($t6)
    ctx->pc = 0x1273d8u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 6));
label_1273dc:
    // 0x1273dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1273dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1273e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1273e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1273e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1273E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1273E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1273E4u;
            // 0x1273e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1273ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

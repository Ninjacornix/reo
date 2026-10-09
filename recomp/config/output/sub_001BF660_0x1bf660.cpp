#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BF660
// Address: 0x1bf660 - 0x1bf810
void sub_001BF660_0x1bf660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BF660_0x1bf660");
#endif

    switch (ctx->pc) {
        case 0x1bf678u: goto label_1bf678;
        case 0x1bf694u: goto label_1bf694;
        case 0x1bf6a0u: goto label_1bf6a0;
        default: break;
    }

    ctx->pc = 0x1bf660u;

    // 0x1bf660: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bf660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bf664: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bf664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bf668: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bf668u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bf66c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bf66cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bf670: 0xc040742  jal         func_101D08
    ctx->pc = 0x1BF670u;
    SET_GPR_U32(ctx, 31, 0x1BF678u);
    ctx->pc = 0x1BF674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF670u;
            // 0x1bf674: 0x27a40028  addiu       $a0, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101D08u;
    if (runtime->hasFunction(0x101D08u)) {
        auto targetFn = runtime->lookupFunction(0x101D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF678u; }
        if (ctx->pc != 0x1BF678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF678u; }
        if (ctx->pc != 0x1BF678u) { return; }
    }
    ctx->pc = 0x1BF678u;
label_1bf678:
    // 0x1bf678: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BF678u;
    {
        const bool branch_taken_0x1bf678 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BF67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF678u;
            // 0x1bf67c: 0x27a40028  addiu       $a0, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf678) {
            ctx->pc = 0x1BF698u;
            goto label_1bf698;
        }
    }
    ctx->pc = 0x1BF680u;
    // 0x1bf680: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1bf680u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1bf684: 0x27a40028  addiu       $a0, $sp, 0x28
    ctx->pc = 0x1bf684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x1bf688: 0x24a56aa0  addiu       $a1, $a1, 0x6AA0
    ctx->pc = 0x1bf688u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27296));
    // 0x1bf68c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1BF68Cu;
    SET_GPR_U32(ctx, 31, 0x1BF694u);
    ctx->pc = 0x1BF690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF68Cu;
            // 0x1bf690: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF694u; }
        if (ctx->pc != 0x1BF694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF694u; }
        if (ctx->pc != 0x1BF694u) { return; }
    }
    ctx->pc = 0x1BF694u;
label_1bf694:
    // 0x1bf694: 0x27a40028  addiu       $a0, $sp, 0x28
    ctx->pc = 0x1bf694u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
label_1bf698:
    // 0x1bf698: 0xc070708  jal         func_1C1C20
    ctx->pc = 0x1BF698u;
    SET_GPR_U32(ctx, 31, 0x1BF6A0u);
    ctx->pc = 0x1C1C20u;
    if (runtime->hasFunction(0x1C1C20u)) {
        auto targetFn = runtime->lookupFunction(0x1C1C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF6A0u; }
        if (ctx->pc != 0x1BF6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1C20_0x1c1c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF6A0u; }
        if (ctx->pc != 0x1BF6A0u) { return; }
    }
    ctx->pc = 0x1BF6A0u;
label_1bf6a0:
    // 0x1bf6a0: 0x93a4002f  lbu         $a0, 0x2F($sp)
    ctx->pc = 0x1bf6a0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 47)));
    // 0x1bf6a4: 0x24080064  addiu       $t0, $zero, 0x64
    ctx->pc = 0x1bf6a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1bf6a8: 0x24060190  addiu       $a2, $zero, 0x190
    ctx->pc = 0x1bf6a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    // 0x1bf6ac: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1bf6acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1bf6b0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1bf6b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1bf6b4: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf6b4u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf6b8: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf6b8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf6bc: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf6bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf6c0: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf6c0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf6c4: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf6c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf6c8: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf6c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf6cc: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf6d0: 0x248407d0  addiu       $a0, $a0, 0x7D0
    ctx->pc = 0x1bf6d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2000));
    // 0x1bf6d4: 0xa6040006  sh          $a0, 0x6($s0)
    ctx->pc = 0x1bf6d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 4));
    // 0x1bf6d8: 0x93a4002e  lbu         $a0, 0x2E($sp)
    ctx->pc = 0x1bf6d8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 46)));
    // 0x1bf6dc: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf6dcu;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf6e0: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf6e0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf6e4: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf6e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf6e8: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf6e8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf6ec: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf6ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf6f0: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf6f0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf6f4: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf6f8: 0xa2040005  sb          $a0, 0x5($s0)
    ctx->pc = 0x1bf6f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 5), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bf6fc: 0x93a4002d  lbu         $a0, 0x2D($sp)
    ctx->pc = 0x1bf6fcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 45)));
    // 0x1bf700: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf700u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf704: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf704u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf708: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf708u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf70c: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf70cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf710: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf710u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf714: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf714u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf718: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf718u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf71c: 0xa2040004  sb          $a0, 0x4($s0)
    ctx->pc = 0x1bf71cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bf720: 0x93a4002b  lbu         $a0, 0x2B($sp)
    ctx->pc = 0x1bf720u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 43)));
    // 0x1bf724: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf724u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf728: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf728u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf72c: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf72cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf730: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf730u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf734: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf734u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf738: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf738u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf73c: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf73cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf740: 0xa2040003  sb          $a0, 0x3($s0)
    ctx->pc = 0x1bf740u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bf744: 0x93a4002a  lbu         $a0, 0x2A($sp)
    ctx->pc = 0x1bf744u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 42)));
    // 0x1bf748: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf748u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf74c: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf74cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf750: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf750u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf754: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf754u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf758: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf758u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf75c: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf75cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf760: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf760u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf764: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1bf764u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bf768: 0x93a40029  lbu         $a0, 0x29($sp)
    ctx->pc = 0x1bf768u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 41)));
    // 0x1bf76c: 0x43903  sra         $a3, $a0, 4
    ctx->pc = 0x1bf76cu;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 4));
    // 0x1bf770: 0x30e9000f  andi        $t1, $a3, 0xF
    ctx->pc = 0x1bf770u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1bf774: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x1bf774u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x1bf778: 0x93880  sll         $a3, $t1, 2
    ctx->pc = 0x1bf778u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x1bf77c: 0xe93821  addu        $a3, $a3, $t1
    ctx->pc = 0x1bf77cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1bf780: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1bf780u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf784: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1bf784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1bf788: 0xa2040001  sb          $a0, 0x1($s0)
    ctx->pc = 0x1bf788u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1bf78c: 0x960b0006  lhu         $t3, 0x6($s0)
    ctx->pc = 0x1bf78cu;
    SET_GPR_U32(ctx, 11, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1bf790: 0x92070005  lbu         $a3, 0x5($s0)
    ctx->pc = 0x1bf790u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1bf794: 0x92040004  lbu         $a0, 0x4($s0)
    ctx->pc = 0x1bf794u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bf798: 0x168001a  div         $zero, $t3, $t0
    ctx->pc = 0x1bf798u;
    { int32_t divisor = GPR_S32(ctx, 8);    int32_t dividend = GPR_S32(ctx, 11);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bf79c: 0xb5082  srl         $t2, $t3, 2
    ctx->pc = 0x1bf79cu;
    SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 11), 2));
    // 0x1bf7a0: 0x16a5021  addu        $t2, $t3, $t2
    ctx->pc = 0x1bf7a0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 10)));
    // 0x1bf7a4: 0x4812  mflo        $t1
    ctx->pc = 0x1bf7a4u;
    SET_GPR_U64(ctx, 9, ctx->lo);
    // 0x1bf7a8: 0x7166001a  div1        $zero, $t3, $a2
    ctx->pc = 0x1bf7a8u;
    { int32_t divisor = GPR_S32(ctx, 6); int32_t dividend = GPR_S32(ctx, 11); if (divisor != 0) {     if (divisor == -1 && dividend == INT32_MIN) {         ctx->lo1 = (uint64_t)(int64_t)INT32_MIN; ctx->hi1 = 0;     } else {         ctx->lo1 = (uint64_t)(int64_t)(dividend / divisor);         ctx->hi1 = (uint64_t)(int64_t)(dividend % divisor);     } } else {     ctx->lo1 = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi1 = (uint64_t)(int64_t)dividend; } }
    // 0x1bf7ac: 0x1494823  subu        $t1, $t2, $t1
    ctx->pc = 0x1bf7acu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x1bf7b0: 0x73040  sll         $a2, $a3, 1
    ctx->pc = 0x1bf7b0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1bf7b4: 0x70004012  mflo1       $t0
    ctx->pc = 0x1bf7b4u;
    SET_GPR_U64(ctx, 8, ctx->lo1);
    // 0x1bf7b8: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1bf7b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1bf7bc: 0x1094021  addu        $t0, $t0, $t1
    ctx->pc = 0x1bf7bcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x1bf7c0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1bf7c0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1bf7c4: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1bf7c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1bf7c8: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x1bf7c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x1bf7cc: 0xc5001a  div         $zero, $a2, $a1
    ctx->pc = 0x1bf7ccu;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bf7d0: 0x0  nop
    ctx->pc = 0x1bf7d0u;
    // NOP
    // 0x1bf7d4: 0x0  nop
    ctx->pc = 0x1bf7d4u;
    // NOP
    // 0x1bf7d8: 0x2812  mflo        $a1
    ctx->pc = 0x1bf7d8u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1bf7dc: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x1bf7dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1bf7e0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1bf7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1bf7e4: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1bf7e4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bf7e8: 0x0  nop
    ctx->pc = 0x1bf7e8u;
    // NOP
    // 0x1bf7ec: 0x0  nop
    ctx->pc = 0x1bf7ecu;
    // NOP
    // 0x1bf7f0: 0x1810  mfhi        $v1
    ctx->pc = 0x1bf7f0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1bf7f4: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1bf7f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bf7f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bf7f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bf7fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bf7fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bf800: 0x3e00008  jr          $ra
    ctx->pc = 0x1BF800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BF804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF800u;
            // 0x1bf804: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BF678u: goto label_1bf678;
            case 0x1BF694u: goto label_1bf694;
            case 0x1BF698u: goto label_1bf698;
            case 0x1BF6A0u: goto label_1bf6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BF808u;
    // 0x1bf808: 0x0  nop
    ctx->pc = 0x1bf808u;
    // NOP
    // 0x1bf80c: 0x0  nop
    ctx->pc = 0x1bf80cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

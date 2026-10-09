#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128198
// Address: 0x128198 - 0x1282a0
void sub_00128198_0x128198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128198_0x128198");
#endif

    switch (ctx->pc) {
        case 0x1281f0u: goto label_1281f0;
        case 0x12823cu: goto label_12823c;
        case 0x128260u: goto label_128260;
        default: break;
    }

    ctx->pc = 0x128198u;

    // 0x128198: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x128198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x12819c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12819cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1281a0: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x1281a0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1281a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1281a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1281a8: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1281a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1281ac: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1281acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1281b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1281b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1281b4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1281b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1281b8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1281b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1281bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1281bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1281c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1281c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1281c4: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1281C4u;
    {
        const bool branch_taken_0x1281c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1281c4) {
            ctx->pc = 0x1281C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1281C4u;
            // 0x1281c8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1281CCu;
            goto label_1281cc;
        }
    }
    ctx->pc = 0x1281CCu;
label_1281cc:
    // 0x1281cc: 0x4012  mflo        $t0
    ctx->pc = 0x1281ccu;
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x1281d0: 0x3810  mfhi        $a3
    ctx->pc = 0x1281d0u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x1281d4: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x1281d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1281d8: 0xa2070000  sb          $a3, 0x0($s0)
    ctx->pc = 0x1281d8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x1281dc: 0x54800004  bnel        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1281DCu;
    {
        const bool branch_taken_0x1281dc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1281dc) {
            ctx->pc = 0x1281E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1281DCu;
            // 0x1281e0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1281F0u;
            goto label_1281f0;
        }
    }
    ctx->pc = 0x1281E4u;
    // 0x1281e4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1281E4u;
    {
        const bool branch_taken_0x1281e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1281E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1281E4u;
            // 0x1281e8: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1281e4) {
            ctx->pc = 0x12822Cu;
            goto label_12822c;
        }
    }
    ctx->pc = 0x1281ECu;
    // 0x1281ec: 0x0  nop
    ctx->pc = 0x1281ecu;
    // NOP
label_1281f0:
    // 0x1281f0: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x1281f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1281f4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1281F4u;
    {
        const bool branch_taken_0x1281f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1281F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1281F4u;
            // 0x1281f8: 0x2053021  addu        $a2, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1281f4) {
            ctx->pc = 0x12822Cu;
            goto label_12822c;
        }
    }
    ctx->pc = 0x1281FCu;
    // 0x1281fc: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1281fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x128200: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x128200u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x128204: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x128204u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x128208: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x128208u;
    {
        const bool branch_taken_0x128208 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x128208) {
            ctx->pc = 0x12820Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128208u;
            // 0x12820c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x128210u;
            goto label_128210;
        }
    }
    ctx->pc = 0x128210u;
label_128210:
    // 0x128210: 0x4012  mflo        $t0
    ctx->pc = 0x128210u;
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x128214: 0x3810  mfhi        $a3
    ctx->pc = 0x128214u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x128218: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x128218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12821c: 0xa0c70000  sb          $a3, 0x0($a2)
    ctx->pc = 0x12821cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x128220: 0x5480fff3  bnel        $a0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x128220u;
    {
        const bool branch_taken_0x128220 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x128220) {
            ctx->pc = 0x128224u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128220u;
            // 0x128224: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1281F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1281f0;
        }
    }
    ctx->pc = 0x128228u;
    // 0x128228: 0xa0c00000  sb          $zero, 0x0($a2)
    ctx->pc = 0x128228u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
label_12822c:
    // 0x12822c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12822cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x128230: 0x24511f08  addiu       $s1, $v0, 0x1F08
    ctx->pc = 0x128230u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 7944));
    // 0x128234: 0xc042c56  jal         func_10B158
    ctx->pc = 0x128234u;
    SET_GPR_U32(ctx, 31, 0x12823Cu);
    ctx->pc = 0x128238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128234u;
            // 0x128238: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12823Cu; }
        if (ctx->pc != 0x12823Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12823Cu; }
        if (ctx->pc != 0x12823Cu) { return; }
    }
    ctx->pc = 0x12823Cu;
label_12823c:
    // 0x12823c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x12823cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128240: 0x2642ffff  addiu       $v0, $s2, -0x1
    ctx->pc = 0x128240u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x128244: 0xe2182a  slt         $v1, $a3, $v0
    ctx->pc = 0x128244u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x128248: 0x43380a  movz        $a3, $v0, $v1
    ctx->pc = 0x128248u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 2));
    // 0x12824c: 0x18e0000b  blez        $a3, . + 4 + (0xB << 2)
    ctx->pc = 0x12824Cu;
    {
        const bool branch_taken_0x12824c = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x128250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12824Cu;
            // 0x128250: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12824c) {
            ctx->pc = 0x12827Cu;
            goto label_12827c;
        }
    }
    ctx->pc = 0x128254u;
    // 0x128254: 0xf11021  addu        $v0, $a3, $s1
    ctx->pc = 0x128254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 17)));
    // 0x128258: 0x2446ffff  addiu       $a2, $v0, -0x1
    ctx->pc = 0x128258u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12825c: 0x0  nop
    ctx->pc = 0x12825cu;
    // NOP
label_128260:
    // 0x128260: 0x2052021  addu        $a0, $s0, $a1
    ctx->pc = 0x128260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x128264: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x128264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x128268: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x128268u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12826c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x12826cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x128270: 0xa7102a  slt         $v0, $a1, $a3
    ctx->pc = 0x128270u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x128274: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x128274u;
    {
        const bool branch_taken_0x128274 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x128278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128274u;
            // 0x128278: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128274) {
            ctx->pc = 0x128260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_128260;
        }
    }
    ctx->pc = 0x12827Cu;
label_12827c:
    // 0x12827c: 0x2051021  addu        $v0, $s0, $a1
    ctx->pc = 0x12827cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x128280: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128280u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128284: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x128284u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128288: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x128288u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12828c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12828cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x128290: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x128290u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x128294: 0x3e00008  jr          $ra
    ctx->pc = 0x128294u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128294u;
            // 0x128298: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1281CCu: goto label_1281cc;
            case 0x1281F0u: goto label_1281f0;
            case 0x128210u: goto label_128210;
            case 0x12822Cu: goto label_12822c;
            case 0x12823Cu: goto label_12823c;
            case 0x128260u: goto label_128260;
            case 0x12827Cu: goto label_12827c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12829Cu;
    // 0x12829c: 0x0  nop
    ctx->pc = 0x12829cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

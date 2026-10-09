#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100218
// Address: 0x100218 - 0x100590
void sub_00100218_0x100218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100218_0x100218");
#endif

    switch (ctx->pc) {
        case 0x10024cu: goto label_10024c;
        case 0x10025cu: goto label_10025c;
        case 0x100280u: goto label_100280;
        case 0x100298u: goto label_100298;
        case 0x1002ecu: goto label_1002ec;
        case 0x100314u: goto label_100314;
        case 0x100388u: goto label_100388;
        case 0x100390u: goto label_100390;
        case 0x1003b8u: goto label_1003b8;
        case 0x1003d0u: goto label_1003d0;
        case 0x1003f8u: goto label_1003f8;
        case 0x100448u: goto label_100448;
        case 0x100460u: goto label_100460;
        case 0x10048cu: goto label_10048c;
        case 0x10049cu: goto label_10049c;
        case 0x1004b0u: goto label_1004b0;
        case 0x100508u: goto label_100508;
        case 0x100560u: goto label_100560;
        default: break;
    }

    ctx->pc = 0x100218u;

    // 0x100218: 0x8047742  j           func_11DD08
    ctx->pc = 0x100218u;
    ctx->pc = 0x11DD08u;
    if (runtime->hasFunction(0x11DD08u)) {
        auto targetFn = runtime->lookupFunction(0x11DD08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011DD08_0x11dd08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x100220u;
    // 0x100220: 0x24030023  addiu       $v1, $zero, 0x23
    ctx->pc = 0x100220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x100224: 0xc  syscall     0
    ctx->pc = 0x100224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x100228: 0x0  nop
    ctx->pc = 0x100228u;
    // NOP
    // 0x10022c: 0x0  nop
    ctx->pc = 0x10022cu;
    // NOP
    // 0x100230: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x100230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x100234: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100238: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100238u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10023c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x10023cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x100240: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100244: 0xc04035e  jal         func_100D78
    ctx->pc = 0x100244u;
    SET_GPR_U32(ctx, 31, 0x10024Cu);
    ctx->pc = 0x100248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100244u;
            // 0x100248: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10024Cu; }
        if (ctx->pc != 0x10024Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10024Cu; }
        if (ctx->pc != 0x10024Cu) { return; }
    }
    ctx->pc = 0x10024Cu;
label_10024c:
    // 0x10024c: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x10024Cu;
    {
        const bool branch_taken_0x10024c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10024Cu;
            // 0x100250: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10024c) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100254u;
    // 0x100254: 0xc047598  jal         func_11D660
    ctx->pc = 0x100254u;
    SET_GPR_U32(ctx, 31, 0x10025Cu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10025Cu; }
        if (ctx->pc != 0x10025Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10025Cu; }
        if (ctx->pc != 0x10025Cu) { return; }
    }
    ctx->pc = 0x10025Cu;
label_10025c:
    // 0x10025c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x10025cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x100260: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x100260u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x100264: 0x8c709f80  lw          $s0, -0x6080($v1)
    ctx->pc = 0x100264u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942592)));
    // 0x100268: 0xac719f80  sw          $s1, -0x6080($v1)
    ctx->pc = 0x100268u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942592), GPR_U32(ctx, 17));
    // 0x10026c: 0xac9c9f84  sw          $gp, -0x607C($a0)
    ctx->pc = 0x10026cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294942596), GPR_U32(ctx, 28));
    // 0x100270: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x100270u;
    {
        const bool branch_taken_0x100270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100270u;
            // 0x100274: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100270) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100278u;
    // 0x100278: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x100278u;
    SET_GPR_U32(ctx, 31, 0x100280u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100280u; }
        if (ctx->pc != 0x100280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100280u; }
        if (ctx->pc != 0x100280u) { return; }
    }
    ctx->pc = 0x100280u;
label_100280:
    // 0x100280: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x100280u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100284:
    // 0x100284: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x100284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100288: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100288u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10028c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10028cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100290: 0x3e00008  jr          $ra
    ctx->pc = 0x100290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100290u;
            // 0x100294: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10024Cu: goto label_10024c;
            case 0x10025Cu: goto label_10025c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100298u: goto label_100298;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002ECu: goto label_1002ec;
            case 0x100314u: goto label_100314;
            case 0x10031Cu: goto label_10031c;
            case 0x100324u: goto label_100324;
            case 0x10032Cu: goto label_10032c;
            case 0x100388u: goto label_100388;
            case 0x100390u: goto label_100390;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100448u: goto label_100448;
            case 0x100460u: goto label_100460;
            case 0x10048Cu: goto label_10048c;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x100508u: goto label_100508;
            case 0x100538u: goto label_100538;
            case 0x100540u: goto label_100540;
            case 0x100560u: goto label_100560;
            case 0x100588u: goto label_100588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100298u;
label_100298:
    // 0x100298: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x100298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10029c: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x10029cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1002a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1002a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1002a4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1002a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1002a8: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x1002a8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x1002ac: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1002acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1002b0: 0x3c040020  lui         $a0, 0x20
    ctx->pc = 0x1002b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32 << 16));
    // 0x1002b4: 0xae037958  sw          $v1, 0x7958($s0)
    ctx->pc = 0x1002b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 3));
    // 0x1002b8: 0x8e027958  lw          $v0, 0x7958($s0)
    ctx->pc = 0x1002b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31064)));
    // 0x1002bc: 0xac82795c  sw          $v0, 0x795C($a0)
    ctx->pc = 0x1002bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31068), GPR_U32(ctx, 2));
    // 0x1002c0: 0x8e037958  lw          $v1, 0x7958($s0)
    ctx->pc = 0x1002c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31064)));
    // 0x1002c4: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1002C4u;
    {
        const bool branch_taken_0x1002c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1002C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002C4u;
            // 0x1002c8: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002c4) {
            ctx->pc = 0x1002E0u;
            goto label_1002e0;
        }
    }
    ctx->pc = 0x1002CCu;
    // 0x1002cc: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x1002ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x1002d0: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1002d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1002d4: 0xac407934  sw          $zero, 0x7934($v0)
    ctx->pc = 0x1002d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
    // 0x1002d8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1002D8u;
    {
        const bool branch_taken_0x1002d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1002DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002D8u;
            // 0x1002dc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002d8) {
            ctx->pc = 0x10032Cu;
            goto label_10032c;
        }
    }
    ctx->pc = 0x1002E0u;
label_1002e0:
    // 0x1002e0: 0x8c447928  lw          $a0, 0x7928($v0)
    ctx->pc = 0x1002e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    // 0x1002e4: 0xc045194  jal         func_114650
    ctx->pc = 0x1002E4u;
    SET_GPR_U32(ctx, 31, 0x1002ECu);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1002ECu; }
        if (ctx->pc != 0x1002ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1002ECu; }
        if (ctx->pc != 0x1002ECu) { return; }
    }
    ctx->pc = 0x1002ECu;
label_1002ec:
    // 0x1002ec: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x1002ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x1002f0: 0x8c627914  lw          $v0, 0x7914($v1)
    ctx->pc = 0x1002f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 30996)));
    // 0x1002f4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1002F4u;
    {
        const bool branch_taken_0x1002f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1002F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1002F4u;
            // 0x1002f8: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1002f4) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x1002FCu;
    // 0x1002fc: 0x8c439f80  lw          $v1, -0x6080($v0)
    ctx->pc = 0x1002fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942592)));
    // 0x100300: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x100300u;
    {
        const bool branch_taken_0x100300 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x100304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100300u;
            // 0x100304: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100300) {
            ctx->pc = 0x10031Cu;
            goto label_10031c;
        }
    }
    ctx->pc = 0x100308u;
    // 0x100308: 0x8c447920  lw          $a0, 0x7920($v0)
    ctx->pc = 0x100308u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31008)));
    // 0x10030c: 0xc045194  jal         func_114650
    ctx->pc = 0x10030Cu;
    SET_GPR_U32(ctx, 31, 0x100314u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100314u; }
        if (ctx->pc != 0x100314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100314u; }
        if (ctx->pc != 0x100314u) { return; }
    }
    ctx->pc = 0x100314u;
label_100314:
    // 0x100314: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100314u;
    {
        const bool branch_taken_0x100314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x100314) {
            ctx->pc = 0x100324u;
            goto label_100324;
        }
    }
    ctx->pc = 0x10031Cu;
label_10031c:
    // 0x10031c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x10031cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100320: 0xac407934  sw          $zero, 0x7934($v0)
    ctx->pc = 0x100320u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31028), GPR_U32(ctx, 0));
label_100324:
    // 0x100324: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x100324u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x100328: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x100328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10032c:
    // 0x10032c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10032cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100330: 0x3e00008  jr          $ra
    ctx->pc = 0x100330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100330u;
            // 0x100334: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10024Cu: goto label_10024c;
            case 0x10025Cu: goto label_10025c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100298u: goto label_100298;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002ECu: goto label_1002ec;
            case 0x100314u: goto label_100314;
            case 0x10031Cu: goto label_10031c;
            case 0x100324u: goto label_100324;
            case 0x10032Cu: goto label_10032c;
            case 0x100388u: goto label_100388;
            case 0x100390u: goto label_100390;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100448u: goto label_100448;
            case 0x100460u: goto label_100460;
            case 0x10048Cu: goto label_10048c;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x100508u: goto label_100508;
            case 0x100538u: goto label_100538;
            case 0x100540u: goto label_100540;
            case 0x100560u: goto label_100560;
            case 0x100588u: goto label_100588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100338u;
    // 0x100338: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x100338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x10033c: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x10033cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x100340: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x100340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x100344: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x100344u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x100348: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x100348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x10034c: 0x3c170020  lui         $s7, 0x20
    ctx->pc = 0x10034cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32 << 16));
    // 0x100350: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x100350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x100354: 0x3c160023  lui         $s6, 0x23
    ctx->pc = 0x100354u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)35 << 16));
    // 0x100358: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x100358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x10035c: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x10035cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x100360: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x100360u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x100364: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x100364u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x100368: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x100368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10036c: 0x3c130020  lui         $s3, 0x20
    ctx->pc = 0x10036cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32 << 16));
    // 0x100370: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100374: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x100374u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x100378: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x100378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x10037c: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x10037cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x100380: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100384: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
label_100388:
    // 0x100388: 0xc045198  jal         func_114660
    ctx->pc = 0x100388u;
    SET_GPR_U32(ctx, 31, 0x100390u);
    ctx->pc = 0x10038Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100388u;
            // 0x10038c: 0x8c447920  lw          $a0, 0x7920($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31008)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100390u; }
        if (ctx->pc != 0x100390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100390u; }
        if (ctx->pc != 0x100390u) { return; }
    }
    ctx->pc = 0x100390u;
label_100390:
    // 0x100390: 0x8e837958  lw          $v1, 0x7958($s4)
    ctx->pc = 0x100390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31064)));
    // 0x100394: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x100394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x100398: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x100398u;
    {
        const bool branch_taken_0x100398 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100398u;
            // 0x10039c: 0x8ee27910  lw          $v0, 0x7910($s7) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 30992)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100398) {
            ctx->pc = 0x1003BCu;
            goto label_1003bc;
        }
    }
    ctx->pc = 0x1003A0u;
    // 0x1003a0: 0xae607934  sw          $zero, 0x7934($s3)
    ctx->pc = 0x1003a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
    // 0x1003a4: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1003a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1003a8: 0xae807958  sw          $zero, 0x7958($s4)
    ctx->pc = 0x1003a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31064), GPR_U32(ctx, 0));
    // 0x1003ac: 0xac407914  sw          $zero, 0x7914($v0)
    ctx->pc = 0x1003acu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 30996), GPR_U32(ctx, 0));
    // 0x1003b0: 0xc045118  jal         func_114460
    ctx->pc = 0x1003B0u;
    SET_GPR_U32(ctx, 31, 0x1003B8u);
    ctx->pc = 0x1003B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1003B0u;
            // 0x1003b4: 0xafc09f94  sw          $zero, -0x606C($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 4294942612), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003B8u; }
        if (ctx->pc != 0x1003B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114460_0x114460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003B8u; }
        if (ctx->pc != 0x1003B8u) { return; }
    }
    ctx->pc = 0x1003B8u;
label_1003b8:
    // 0x1003b8: 0x8ee27910  lw          $v0, 0x7910($s7)
    ctx->pc = 0x1003b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 30992)));
label_1003bc:
    // 0x1003bc: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1003BCu;
    {
        const bool branch_taken_0x1003bc = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1003C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1003BCu;
            // 0x1003c0: 0x26c47480  addiu       $a0, $s6, 0x7480 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 29824));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1003bc) {
            ctx->pc = 0x1003D0u;
            goto label_1003d0;
        }
    }
    ctx->pc = 0x1003C4u;
    // 0x1003c4: 0x8e459f80  lw          $a1, -0x6080($s2)
    ctx->pc = 0x1003c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
    // 0x1003c8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1003C8u;
    SET_GPR_U32(ctx, 31, 0x1003D0u);
    ctx->pc = 0x1003CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1003C8u;
            // 0x1003cc: 0x8e26795c  lw          $a2, 0x795C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003D0u; }
        if (ctx->pc != 0x1003D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003D0u; }
        if (ctx->pc != 0x1003D0u) { return; }
    }
    ctx->pc = 0x1003D0u;
label_1003d0:
    // 0x1003d0: 0x8e439f80  lw          $v1, -0x6080($s2)
    ctx->pc = 0x1003d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
    // 0x1003d4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1003D4u;
    {
        const bool branch_taken_0x1003d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1003d4) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003DCu;
    // 0x1003dc: 0x8e22795c  lw          $v0, 0x795C($s1)
    ctx->pc = 0x1003dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
    // 0x1003e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1003E0u;
    {
        const bool branch_taken_0x1003e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1003e0) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003E8u;
    // 0x1003e8: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x1003e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1003ec: 0x8ebc9f84  lw          $gp, -0x607C($s5)
    ctx->pc = 0x1003ecu;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942596)));
    // 0x1003f0: 0x60f809  jalr        $v1
    ctx->pc = 0x1003F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1003F8u);
        ctx->pc = 0x1003F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1003F0u;
            // 0x1003f4: 0x8e24795c  lw          $a0, 0x795C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1003F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10024Cu: goto label_10024c;
            case 0x10025Cu: goto label_10025c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100298u: goto label_100298;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002ECu: goto label_1002ec;
            case 0x100314u: goto label_100314;
            case 0x10031Cu: goto label_10031c;
            case 0x100324u: goto label_100324;
            case 0x10032Cu: goto label_10032c;
            case 0x100388u: goto label_100388;
            case 0x100390u: goto label_100390;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100448u: goto label_100448;
            case 0x100460u: goto label_100460;
            case 0x10048Cu: goto label_10048c;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x100508u: goto label_100508;
            case 0x100538u: goto label_100538;
            case 0x100540u: goto label_100540;
            case 0x100560u: goto label_100560;
            case 0x100588u: goto label_100588;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1003F8u; }
            if (ctx->pc != 0x1003F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1003F8u;
label_1003f8:
    // 0x1003f8: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x1003f8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1003fc:
    // 0x1003fc: 0xae607934  sw          $zero, 0x7934($s3)
    ctx->pc = 0x1003fcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
    // 0x100400: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x100400u;
    {
        const bool branch_taken_0x100400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100400u;
            // 0x100404: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100400) {
            ctx->pc = 0x100388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100388;
        }
    }
    ctx->pc = 0x100408u;
    // 0x100408: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x100408u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10040c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x10040cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x100410: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100414: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x100414u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x100418: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100418u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10041c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x10041cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x100420: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x100420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x100424: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x100424u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x100428: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10042c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x10042cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100430: 0x8e847914  lw          $a0, 0x7914($s4)
    ctx->pc = 0x100430u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30996)));
    // 0x100434: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x100434u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100438: 0x1480001a  bnez        $a0, . + 4 + (0x1A << 2)
    ctx->pc = 0x100438u;
    {
        const bool branch_taken_0x100438 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10043Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100438u;
            // 0x10043c: 0xffbf0050  sd          $ra, 0x50($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100438) {
            ctx->pc = 0x1004A4u;
            goto label_1004a4;
        }
    }
    ctx->pc = 0x100440u;
    // 0x100440: 0xc045144  jal         func_114510
    ctx->pc = 0x100440u;
    SET_GPR_U32(ctx, 31, 0x100448u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100448u; }
        if (ctx->pc != 0x100448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100448u; }
        if (ctx->pc != 0x100448u) { return; }
    }
    ctx->pc = 0x100448u;
label_100448:
    // 0x100448: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x100448u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x10044c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x10044cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x100450: 0xac629f98  sw          $v0, -0x6068($v1)
    ctx->pc = 0x100450u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942616), GPR_U32(ctx, 2));
    // 0x100454: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x100454u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100458: 0xc045148  jal         func_114520
    ctx->pc = 0x100458u;
    SET_GPR_U32(ctx, 31, 0x100460u);
    ctx->pc = 0x10045Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100458u;
            // 0x10045c: 0x24a59fa0  addiu       $a1, $a1, -0x6060 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100460u; }
        if (ctx->pc != 0x100460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100460u; }
        if (ctx->pc != 0x100460u) { return; }
    }
    ctx->pc = 0x100460u;
label_100460:
    // 0x100460: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x100460u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x100464: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x100468: 0x24639fd0  addiu       $v1, $v1, -0x6030
    ctx->pc = 0x100468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294942672));
    // 0x10046c: 0x24420338  addiu       $v0, $v0, 0x338
    ctx->pc = 0x10046cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x100470: 0xac70000c  sw          $s0, 0xC($v1)
    ctx->pc = 0x100470u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 16));
    // 0x100474: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x100474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100478: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x100478u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x10047c: 0xac720008  sw          $s2, 0x8($v1)
    ctx->pc = 0x10047cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 18));
    // 0x100480: 0xac710014  sw          $s1, 0x14($v1)
    ctx->pc = 0x100480u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 17));
    // 0x100484: 0xc045108  jal         func_114420
    ctx->pc = 0x100484u;
    SET_GPR_U32(ctx, 31, 0x10048Cu);
    ctx->pc = 0x100488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100484u;
            // 0x100488: 0xac600010  sw          $zero, 0x10($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10048Cu; }
        if (ctx->pc != 0x10048Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10048Cu; }
        if (ctx->pc != 0x10048Cu) { return; }
    }
    ctx->pc = 0x10048Cu;
label_10048c:
    // 0x10048c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10048cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100490: 0xae827914  sw          $v0, 0x7914($s4)
    ctx->pc = 0x100490u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 30996), GPR_U32(ctx, 2));
    // 0x100494: 0xc045110  jal         func_114440
    ctx->pc = 0x100494u;
    SET_GPR_U32(ctx, 31, 0x10049Cu);
    ctx->pc = 0x100498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100494u;
            // 0x100498: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10049Cu; }
        if (ctx->pc != 0x10049Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10049Cu; }
        if (ctx->pc != 0x10049Cu) { return; }
    }
    ctx->pc = 0x10049Cu;
label_10049c:
    // 0x10049c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10049Cu;
    {
        const bool branch_taken_0x10049c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1004A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10049Cu;
            // 0x1004a0: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10049c) {
            ctx->pc = 0x1004B4u;
            goto label_1004b4;
        }
    }
    ctx->pc = 0x1004A4u;
label_1004a4:
    // 0x1004a4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1004a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1004a8: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x1004A8u;
    SET_GPR_U32(ctx, 31, 0x1004B0u);
    ctx->pc = 0x1004ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1004A8u;
            // 0x1004ac: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1004B0u; }
        if (ctx->pc != 0x1004B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1004B0u; }
        if (ctx->pc != 0x1004B0u) { return; }
    }
    ctx->pc = 0x1004B0u;
label_1004b0:
    // 0x1004b0: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1004b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1004b4:
    // 0x1004b4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1004b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1004b8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1004b8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1004bc: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1004bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1004c0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1004c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1004c4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1004c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1004c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1004c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1004cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1004CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1004D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004CCu;
            // 0x1004d0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10024Cu: goto label_10024c;
            case 0x10025Cu: goto label_10025c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            case 0x100298u: goto label_100298;
            case 0x1002E0u: goto label_1002e0;
            case 0x1002ECu: goto label_1002ec;
            case 0x100314u: goto label_100314;
            case 0x10031Cu: goto label_10031c;
            case 0x100324u: goto label_100324;
            case 0x10032Cu: goto label_10032c;
            case 0x100388u: goto label_100388;
            case 0x100390u: goto label_100390;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            case 0x100448u: goto label_100448;
            case 0x100460u: goto label_100460;
            case 0x10048Cu: goto label_10048c;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            case 0x100508u: goto label_100508;
            case 0x100538u: goto label_100538;
            case 0x100540u: goto label_100540;
            case 0x100560u: goto label_100560;
            case 0x100588u: goto label_100588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1004D4u;
    // 0x1004d4: 0x0  nop
    ctx->pc = 0x1004d4u;
    // NOP
    // 0x1004d8: 0x3c052000  lui         $a1, 0x2000
    ctx->pc = 0x1004d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)8192 << 16));
    // 0x1004dc: 0x853825  or          $a3, $a0, $a1
    ctx->pc = 0x1004dcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1004e0: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1004e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1004e4: 0x18400014  blez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1004E4u;
    {
        const bool branch_taken_0x1004e4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1004E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004E4u;
            // 0x1004e8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1004e4) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004ECu;
    // 0x1004ec: 0x8ce90008  lw          $t1, 0x8($a3)
    ctx->pc = 0x1004ecu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1004f0: 0x18400011  blez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1004F0u;
    {
        const bool branch_taken_0x1004f0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1004F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004F0u;
            // 0x1004f4: 0x1255025  or          $t2, $t1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 9) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1004f0) {
            ctx->pc = 0x100538u;
            goto label_100538;
        }
    }
    ctx->pc = 0x1004F8u;
    // 0x1004f8: 0x24e80010  addiu       $t0, $a3, 0x10
    ctx->pc = 0x1004f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x1004fc: 0x3c0b0020  lui         $t3, 0x20
    ctx->pc = 0x1004fcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32 << 16));
    // 0x100500: 0x1061021  addu        $v0, $t0, $a2
    ctx->pc = 0x100500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x100504: 0x0  nop
    ctx->pc = 0x100504u;
    // NOP
label_100508:
    // 0x100508: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x100508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x10050c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x10050cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x100510: 0x1262021  addu        $a0, $t1, $a2
    ctx->pc = 0x100510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x100514: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x100514u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x100518: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x100518u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x10051c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x10051cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100520: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x100520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x100524: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x100524u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x100528: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x100528u;
    {
        const bool branch_taken_0x100528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10052Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100528u;
            // 0x10052c: 0x1061021  addu        $v0, $t0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100528) {
            ctx->pc = 0x100508u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100508;
        }
    }
    ctx->pc = 0x100530u;
    // 0x100530: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x100530u;
    {
        const bool branch_taken_0x100530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100530u;
            // 0x100534: 0x8ce30004  lw          $v1, 0x4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100530) {
            ctx->pc = 0x100540u;
            goto label_100540;
        }
    }
    ctx->pc = 0x100538u;
label_100538:
    // 0x100538: 0x3c0b0020  lui         $t3, 0x20
    ctx->pc = 0x100538u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32 << 16));
    // 0x10053c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x10053cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
label_100540:
    // 0x100540: 0x18600011  blez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x100540u;
    {
        const bool branch_taken_0x100540 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100540u;
            // 0x100544: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100540) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100548u;
    // 0x100548: 0x8ce9000c  lw          $t1, 0xC($a3)
    ctx->pc = 0x100548u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x10054c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x10054cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100550: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x100550u;
    {
        const bool branch_taken_0x100550 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100550u;
            // 0x100554: 0x1225025  or          $t2, $t1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100550) {
            ctx->pc = 0x100588u;
            goto label_100588;
        }
    }
    ctx->pc = 0x100558u;
    // 0x100558: 0x24e80050  addiu       $t0, $a3, 0x50
    ctx->pc = 0x100558u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 80));
    // 0x10055c: 0x1061021  addu        $v0, $t0, $a2
    ctx->pc = 0x10055cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
label_100560:
    // 0x100560: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x100560u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x100564: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x100564u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x100568: 0x1262021  addu        $a0, $t1, $a2
    ctx->pc = 0x100568u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x10056c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10056cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x100570: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x100570u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100574: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x100574u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x100578: 0x8ce20004  lw          $v0, 0x4($a3)
    ctx->pc = 0x100578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x10057c: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x10057cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x100580: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x100580u;
    {
        const bool branch_taken_0x100580 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100580u;
            // 0x100584: 0x1061021  addu        $v0, $t0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100580) {
            ctx->pc = 0x100560u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100560;
        }
    }
    ctx->pc = 0x100588u;
label_100588:
    // 0x100588: 0x80400a6  j           func_100298
    ctx->pc = 0x100588u;
    ctx->pc = 0x10058Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100588u;
            // 0x10058c: 0x25647958  addiu       $a0, $t3, 0x7958 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 11), 31064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100298u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_100298;
    ctx->pc = 0x100590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
